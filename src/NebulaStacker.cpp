#include "NebulaStacker.hpp"
#include "Images.hpp"
#include "ImageIO.hpp"
#include <boost/gil/extension/numeric/pixel_numeric_operations.hpp>
#include <boost/gil/extension/numeric/algorithm.hpp>

#include <iostream>

NebulaStacker::NebulaStacker(ImageReader& imageReader, ImageWriter& imageWriter)
    : imageReader(imageReader), imageWriter(imageWriter)
{
}

void NebulaStacker::setLightFrames(const Strings& lightFrames)
{
    this->lightFrames = lightFrames;
}

void NebulaStacker::stack(const std::string& outputFilename)
{
    AccumImage accumulator;
    for (auto frameFile : lightFrames)
    {
        auto frame = imageReader.readImage(frameFile);
        if (view(accumulator).size() == 0)
        {
            accumulator.recreate(frame.dimensions());
            fill_pixels(view(accumulator), Color::black());
        }
        boost::gil::transform_pixels(const_view(frame), const_view(accumulator), view(accumulator), boost::gil::pixel_plus_t<RawPixel, AccumPixel, AccumPixel>());
    }
    RawImage output(accumulator.dimensions());
    boost::gil::view_divides_scalar<AccumPixel>(const_view(accumulator), lightFrames.size(), view(output));
    imageWriter.writeImage(outputFilename, output);
}
