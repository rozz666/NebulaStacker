#include "TiffImageWriter.hpp"
#include <boost/gil/extension/io/tiff_dynamic_io.hpp>

void TiffImageWriter::writeImage(const std::string& filename, const RawImage& image)
{
    boost::gil::tiff_write_view(filename, const_view(image));
}

