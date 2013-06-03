#ifndef TIFFIMAGEREADER_HPP
#define TIFFIMAGEREADER_HPP
#include "ImageReader.hpp"

struct TiffImageReader : public ImageReader
{
    virtual RawImage readImage(const std::string& filename);
};

#endif // TIFFIMAGEREADER_HPP
