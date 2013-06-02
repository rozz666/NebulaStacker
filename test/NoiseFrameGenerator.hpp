#ifndef NOISEFRAMEGENERATOR_HPP
#define NOISEFRAMEGENERATOR_HPP
#include <Images.hpp>
#include <boost/random/mersenne_twister.hpp>

class NoiseFrameGenerator
{
public:
    NoiseFrameGenerator()
        : frameCount(1), noiseAmplitude(0) { }
    NoiseFrameGenerator& frames(unsigned count);
    NoiseFrameGenerator& from(RawImage frame);
    NoiseFrameGenerator& withAmplitude(Accumulator amplitude);
    RawImages build();
private:
    unsigned frameCount;
    RawImage frame;
    Accumulator noiseAmplitude;
};

#endif // NOISEFRAMEGENERATOR_HPP
