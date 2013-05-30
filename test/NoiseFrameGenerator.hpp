#ifndef NOISEFRAMEGENERATOR_HPP
#define NOISEFRAMEGENERATOR_HPP
#include <Images.hpp>

class NoiseFrameGenerator
{
public:
    NoiseFrameGenerator& frames(unsigned count);
    NoiseFrameGenerator& from(RawImage frame);
    NoiseFrameGenerator& withAmplitude(float amplitude);
    RawImages build();
};

#endif // NOISEFRAMEGENERATOR_HPP
