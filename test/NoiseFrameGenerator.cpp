#include "NoiseFrameGenerator.hpp"

NoiseFrameGenerator& NoiseFrameGenerator::frames(unsigned int count)
{
    return *this;
}

NoiseFrameGenerator& NoiseFrameGenerator::from(RawImage frame)
{
    return *this;
}

NoiseFrameGenerator& NoiseFrameGenerator::withAmplitude(float amplitude)
{
    return *this;
}

RawImages NoiseFrameGenerator::build()
{
    return RawImages();
}
