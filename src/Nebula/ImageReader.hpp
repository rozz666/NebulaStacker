#ifndef NEBULA_IMAGEREADER_HPP
#define NEBULA_IMAGEREADER_HPP
#include <Nebula/Images.hpp>

namespace Nebula
{

struct ImageReader
{
    virtual ~ImageReader() { }
    virtual RawImage readImage(const std::string& filename) = 0;
};

}

#endif // NEBULA_IMAGEREADER_HPP
