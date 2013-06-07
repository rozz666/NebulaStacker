#ifndef IMAGEWRITER_HPP
#define IMAGEWRITER_HPP
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

#endif // IMAGEWRITER_HPP
