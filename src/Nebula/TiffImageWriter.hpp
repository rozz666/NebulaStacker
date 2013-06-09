#ifndef NEBULA_TIFFIMAGEWRITER_HPP
#define NEBULA_TIFFIMAGEWRITER_HPP
#include <Nebula/ImageWriter.hpp>

namespace Nebula
{

struct TiffImageWriter : public ImageWriter
{
    virtual void writeImage(const std::string& filename, const RawImage& image);
};

}

#endif // NEBULA_TIFFIMAGEWRITER_HPP
