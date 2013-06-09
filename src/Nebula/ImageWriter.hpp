#ifndef NEBULA_IMAGEWRITER_HPP
#define NEBULA_IMAGEWRITER_HPP
#include <string>
#include <Nebula/Images.hpp>

namespace Nebula
{

struct ImageWriter
{
    virtual ~ImageWriter() { }
    virtual void writeImage(const std::string& filename, const RawImage& image) = 0;
};

}

#endif // NEBULA_IMAGEWRITER_HPP
