#include "NebulaStacker.hpp"
#include "Images.hpp"
#include "ImageIO.hpp"

void NebulaStacker::setLightFrames(const Strings& lightFrames)
{
    this->lightFrames = lightFrames;
}

void NebulaStacker::stack(const std::string& outputFilename)
{
    auto output = readTiffImage(lightFrames[0]);
    writeTiffImage(outputFilename, output);
}
