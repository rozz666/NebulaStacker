#ifndef IMAGEREADER_HPP
#define IMAGEREADER_HPP
#include <Nebula/Images.hpp>

namespace Nebula
{

struct ImageReader
{
    virtual ~ImageReader() { }
    virtual RawImage readImage(const std::string& filename) = 0;
};

}

#endif // IMAGEREADER_HPP
