#ifndef IMAGEWRITER_HPP
#define IMAGEWRITER_HPP
#include <string>
#include "Images.hpp"

struct ImageWriter
{
    virtual ~ImageWriter() { }
    virtual void writeImage(const std::string& filename, const RawImage& image) = 0;
};

#endif // IMAGEWRITER_HPP
