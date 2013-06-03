#ifndef IMAGEREADER_HPP
#define IMAGEREADER_HPP
#include "Images.hpp"

struct ImageReader
{
    virtual ~ImageReader() { }
    virtual RawImage readImage(const std::string& filename) = 0;
};

#endif // IMAGEREADER_HPP
