#include "FrameFiles.hpp"
#include <boost/gil/extension/io/tiff_dynamic_io.hpp>
#include <gtest/gtest.h>

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
