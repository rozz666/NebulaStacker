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
    boost::mt19937 rng;
    unsigned frameCount;
    RawImage frame;
    Accumulator noiseAmplitude;

    RawImage generateNoisyFrame();
};

#endif // NOISEFRAMEGENERATOR_HPP
