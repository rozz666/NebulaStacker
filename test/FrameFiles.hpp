#ifndef FRAMEFILES_HPP
#define FRAMEFILES_HPP
#include <vector>
#include <boost/gil/image.hpp>
#include "ApplicationFixture.hpp"
#include <Images.hpp>

class FrameFiles
{
public:
    void writeFrames(RawImages, Strings) { }
    void expectIdenticalImages(RawImage, std::string) { }
};

#endif // FRAMEFILES_HPP
