#ifndef TIFFIMAGEWRITER_HPP
#define TIFFIMAGEWRITER_HPP
#include <Nebula/ImageWriter.hpp>

namespace Nebula
{

struct TiffImageWriter : public ImageWriter
{
    virtual void writeImage(const std::string& filename, const RawImage& image);
};

}

#endif // TIFFIMAGEWRITER_HPP
