#ifndef FRAMEFILES_HPP
#define FRAMEFILES_HPP
#include "AutoremoveFiles.hpp"
#include <Images.hpp>

class FrameFiles
{
public:
    void writeFrames(RawImages frames, Strings frameFilenames);
    Strings writeFrames(RawImages frames);
    void expectIdenticalImages(std::string expectedFilename, std::string actualFilename);
    void expectAverageDifference(RawImage expected, std::string actualFilename, float expectedDifference);
private:
    AutoremoveFiles filesToRemove;

    static std::string genInputFileName(unsigned index);
    std::string writeInputFrame(const RawImage& frame, unsigned index);
};

#endif // FRAMEFILES_HPP
