#ifndef FRAMEFILES_HPP
#define FRAMEFILES_HPP
#include "AutoremoveFiles.hpp"
#include <Images.hpp>

class FrameFiles
{
public:
    void writeFrames(RawImages frames, Strings frameFilenames);
    void expectIdenticalImages(std::string expectedFilename, std::string actualFilename);
private:
    AutoremoveFiles filesToRemove;
};

#endif // FRAMEFILES_HPP
