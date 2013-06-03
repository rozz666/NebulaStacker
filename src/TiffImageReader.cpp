#include "TiffImageReader.hpp"
#include "ImageIO.hpp"

RawImage TiffImageReader::readImage(const std::string& filename)
{
    return readTiffImage(filename);
}


