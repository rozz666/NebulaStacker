#include "TiffImageWriter.hpp"
#include "ImageIO.hpp"

void TiffImageWriter::writeImage(const std::string& filename, const RawImage& image)
{
    writeTiffImage(filename, image);
}

