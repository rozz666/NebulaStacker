#include <Nebula/Stacker.hpp>
#include <Nebula/Images.hpp>

namespace Nebula
{

Stacker::Stacker(ImageReader& imageReader, ImageWriter& imageWriter, FrameCombinerFactory& frameCombinerFactory)
    : imageReader(imageReader), imageWriter(imageWriter), frameCombinerFactory(frameCombinerFactory)
{
}

void Stacker::setLightFrames(const Strings& lightFrames)
{
    this->lightFrames = lightFrames;
}

void Stacker::stack(const std::string& outputFilename)
{
    FrameCombinerPtr combiner = frameCombinerFactory.createFrameCombiner();
    for (auto frameFile : lightFrames)
        combiner->addFrame(imageReader.readImage(frameFile));
    imageWriter.writeImage(outputFilename, combiner->getCombinedFrame());
}

}
