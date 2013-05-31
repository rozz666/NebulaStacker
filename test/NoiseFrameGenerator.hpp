#ifndef NOISEFRAMEGENERATOR_HPP
#define NOISEFRAMEGENERATOR_HPP
#include <Images.hpp>

class NoiseFrameGenerator
{
public:
    NoiseFrameGenerator() : frameCount(1) { }
    NoiseFrameGenerator& frames(unsigned count);
    NoiseFrameGenerator& from(RawImage frame);
    NoiseFrameGenerator& withAmplitude(float amplitude);
    RawImages build();
private:
    unsigned frameCount;
    RawImage frame;
};

#endif // NOISEFRAMEGENERATOR_HPP
