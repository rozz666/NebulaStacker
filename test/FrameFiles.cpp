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

void FrameFiles::expectAverageDifference(RawImage expected, std::string actualFilename, float expectedDifference)
{
    FAIL() << "not implemented";
}
