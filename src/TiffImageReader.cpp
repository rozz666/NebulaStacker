#include "TiffImageReader.hpp"
#include <boost/gil/extension/io/tiff_dynamic_io.hpp>

RawImage TiffImageReader::readImage(const std::string& filename)
{
    RawImage image;
    boost::gil::tiff_read_image(filename, image);
    return image;
}


