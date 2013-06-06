#ifndef FRAMEFILES_HPP
#define FRAMEFILES_HPP
#include "AutoremoveFiles.hpp"
#include <Images.hpp>
#include <TiffImageReader.hpp>
#include <TiffImageWriter.hpp>

class FrameFiles
{
public:
    FrameFiles() : fileIndex(1) { }
    void writeFrames(RawImages frames, Strings frameFilenames);
    Strings writeFrames(RawImages frames);
    void expectIdenticalImages(std::string expectedFilename, std::string actualFilename);
    void expectAverageDifference(RawImage expected, std::string actualFilename, double expectedDifference);
private:
    AutoremoveFiles filesToRemove;
    TiffImageReader imageReader;
    TiffImageWriter imageWriter;
    unsigned fileIndex;

    template <typename View1, typename View2>
    double averageDifference(const View1& view1, const View2& view2);

    std::string genInputFileName();
    std::string writeInputFrame(const RawImage& frame);
};

#endif // FRAMEFILES_HPP
