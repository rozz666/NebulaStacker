#include "ImageIO.hpp"
#include <boost/gil/extension/io/tiff_dynamic_io.hpp>

RawImage readTiffImage(const std::string& filename)
{
    RawImage image;
    boost::gil::tiff_read_image(filename, image);
    return image;
}

void writeTiffImage(const std::string& filename, const RawImage& image)
{
    boost::gil::tiff_write_view(filename, const_view(image));
}
