#include "NoiseFrameGenerator.hpp"

NoiseFrameGenerator& NoiseFrameGenerator::frames(unsigned int count)
{
    frameCount = count;
    return *this;
}

NoiseFrameGenerator& NoiseFrameGenerator::from(RawImage frame)
{
    this->frame = frame;
    return *this;
}

NoiseFrameGenerator& NoiseFrameGenerator::withAmplitude(float amplitude)
{
    return *this;
}

RawImages NoiseFrameGenerator::build()
{
    return RawImages(frameCount, frame);
}
