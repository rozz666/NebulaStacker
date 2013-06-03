#ifndef TIFFIMAGEWRITER_HPP
#define TIFFIMAGEWRITER_HPP
#include "ImageWriter.hpp"

struct TiffImageWriter : public ImageWriter
{
    virtual void writeImage(const std::string& filename, const RawImage& image);
};

#endif // TIFFIMAGEWRITER_HPP
