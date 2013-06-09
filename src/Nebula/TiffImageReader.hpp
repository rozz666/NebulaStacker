#ifndef NEBULA_TIFFIMAGEREADER_HPP
#define NEBULA_TIFFIMAGEREADER_HPP
#include <Nebula/ImageReader.hpp>

namespace Nebula
{

struct TiffImageReader : public ImageReader
{
    virtual RawImage readImage(const std::string& filename);
};

}

#endif // NEBULA_TIFFIMAGEREADER_HPP
