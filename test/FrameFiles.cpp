#include "FrameFiles.hpp"
#include <gtest/gtest.h>
#include <ImageIO.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/range.hpp>

void FrameFiles::writeFrames(RawImages frames, Strings frameFilenames)
{
    for (std::size_t i = 0; i != frames.size(); ++i)
    {
        writeTiffImage(frameFilenames[i], frames[i]);
        filesToRemove.add(frameFilenames[i]);
    }
}
void FrameFiles::expectIdenticalImages(std::string expectedFilename, std::string actualFilename)
{
    auto expected = readTiffImage(expectedFilename);
    auto actual = readTiffImage(actualFilename);
    ASSERT_TRUE(expected == actual) << actualFilename << " not identical to " << expectedFilename;
}
Strings FrameFiles::writeFrames(RawImages frames)
{
    Strings filenames;
    for (const auto& frame : frames)
        filenames.push_back(writeInputFrame(frame));
    return filenames;
}

std::string FrameFiles::genInputFileName()
{
    fileIndex++;
    return "input" + boost::lexical_cast<std::string>(fileIndex) + ".tif";
}

std::string FrameFiles::writeInputFrame(const RawImage& frame)
{
    auto filename = genInputFileName();
    writeTiffImage(filename, frame);
    filesToRemove.add(filename);
    return filename;
}

template <typename View1, typename View2>
double FrameFiles::averageDifference(const View1& view1, const View2& view2)
{
    double difference = 0;
    typedef typename boost::gil::channel_type<View1>::type Channel;
    for (std::ptrdiff_t y = 0; y < view1.height(); ++y)
    {
        typename View1::x_iterator it1 = view1.row_begin(y);
        typename View2::x_iterator it2 = view2.row_begin(y);

        for (; it1 != view1.row_end(y); ++it1, ++it2)
        {
            boost::gil::static_for_each(*it1, *it2, [&](Channel ch1, Channel ch2) { difference += std::abs(double(ch1) - ch2); });
        }
    }
    return difference / (view1.width() * view1.height() * boost::gil::num_channels<View1>::value);
}

void FrameFiles::expectAverageDifference(RawImage expected, std::string actualFilename, double expectedDifference)
{
    auto actual = readTiffImage(actualFilename);

    ASSERT_EQ(expected.dimensions(), actual.dimensions());
    ASSERT_LE(averageDifference(const_view(expected), const_view(actual)), expectedDifference);
}
