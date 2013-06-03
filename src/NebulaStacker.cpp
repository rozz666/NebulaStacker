#include "NebulaStacker.hpp"
#include "Images.hpp"

NebulaStacker::NebulaStacker(ImageReader& imageReader, ImageWriter& imageWriter, FrameCombinerFactory& frameCombinerFactory)
    : imageReader(imageReader), imageWriter(imageWriter), frameCombinerFactory(frameCombinerFactory)
{
}

void NebulaStacker::setLightFrames(const Strings& lightFrames)
{
    this->lightFrames = lightFrames;
}

void NebulaStacker::stack(const std::string& outputFilename)
{
    FrameCombinerPtr combiner = frameCombinerFactory.createFrameCombiner();
    for (auto frameFile : lightFrames)
        combiner->addFrame(imageReader.readImage(frameFile));
    imageWriter.writeImage(outputFilename, combiner->getCombinedFrame());
}
