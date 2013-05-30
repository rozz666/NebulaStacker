#include "FrameFiles.hpp"
#include <boost/gil/extension/io/tiff_dynamic_io.hpp>
#include <gtest/gtest.h>
#include <boost/lexical_cast.hpp>
#include <boost/range.hpp>

void FrameFiles::writeFrames(RawImages frames, Strings frameFilenames)
{
    for (std::size_t i = 0; i != frames.size(); ++i)
    {
        boost::gil::tiff_write_view(frameFilenames[i], const_view(frames[i]));
        filesToRemove.add(frameFilenames[i]);
    }
}
void FrameFiles::expectIdenticalImages(std::string expectedFilename, std::string actualFilename)
{
    RawImage expected, actual;
    boost::gil::tiff_read_image(expectedFilename, expected);
    boost::gil::tiff_read_image(actualFilename, actual);
    ASSERT_TRUE(expected == actual) << actualFilename << " not identical to " << expectedFilename;
}
Strings FrameFiles::writeFrames(RawImages frames)
{
    Strings filenames;
    for (std::size_t i = 0; i != frames.size(); ++i)
        filenames.push_back(writeInputFrame(frames[i], i));
    return filenames;
}

std::string FrameFiles::genInputFileName(unsigned int index)
{
    return "input" + boost::lexical_cast<std::string>(index) + ".tif";
}

std::string FrameFiles::writeInputFrame(const RawImage& frame, unsigned int index)
{
    auto filename = genInputFileName(index);
    boost::gil::tiff_write_view(filename, const_view(frame));
    filesToRemove.add(filename);
    return filename;
}

void FrameFiles::expectAverageDifference(RawImage expected, std::string actualFilename, float expectedDifference)
{
    FAIL() << "not implemented";
}
