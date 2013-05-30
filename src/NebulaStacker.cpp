#include "NebulaStacker.hpp"
#include "Images.hpp"
#include <boost/gil/extension/io/tiff_dynamic_io.hpp>

void NebulaStacker::setLightFrames(const Strings& lightFrames)
{
    this->lightFrames = lightFrames;
}

void NebulaStacker::stack(const std::string& outputFilename)
{
    RawImage output;
    boost::gil::tiff_read_image(lightFrames[0], output);
    boost::gil::tiff_write_view(outputFilename, const_view(output));
}
