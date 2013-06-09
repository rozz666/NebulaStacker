#include <Nebula/FrameFiles.hpp>
#include <gtest/gtest.h>
#include <Nebula/GilAlgorithm.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/range.hpp>
#include <Nebula/RawImagePrinter.hpp>

namespace Nebula
{

void FrameFiles::writeFrames(RawImages frames, Strings frameFilenames)
{
    for (std::size_t i = 0; i != frames.size(); ++i)
    {
        imageWriter.writeImage(frameFilenames[i], frames[i]);
        filesToRemove.add(frameFilenames[i]);
    }
}
void FrameFiles::expectIdenticalImages(std::string expectedFilename, std::string actualFilename)
{
    auto expected = imageReader.readImage(expectedFilename);
    auto actual = imageReader.readImage(actualFilename);
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
    imageWriter.writeImage(filename, frame);
    filesToRemove.add(filename);
    return filename;
}

template <typename View1, typename View2>
double FrameFiles::averageDifference(const View1& view1, const View2& view2)
{
    auto difference = for_each_channel_accumulate(view1, view2, 0.0, [](double ch1, double ch2)
    {
        return std::abs(ch1 - ch2); 
    });
    return difference / (view1.size() * boost::gil::num_channels<View1>::value);
}

void FrameFiles::expectAverageDifference(RawImage expected, std::string actualFilename, double expectedDifference)
{
    auto actual = imageReader.readImage(actualFilename);

    ASSERT_EQ(expected.dimensions(), actual.dimensions());
    ASSERT_LE(averageDifference(const_view(expected), const_view(actual)), expectedDifference);
}

}
