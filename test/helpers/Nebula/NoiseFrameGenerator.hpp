#ifndef NEBULA_NOISEFRAMEGENERATOR_HPP
#define NEBULA_NOISEFRAMEGENERATOR_HPP
#include <Nebula/Images.hpp>
#include <Nebula/Point.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>

namespace Nebula
{

class NoiseFrameGenerator
{
public:
    NoiseFrameGenerator()
        : frameCount(1), noiseAmplitude(0) { }
    NoiseFrameGenerator& frames(unsigned count);
    NoiseFrameGenerator& from(RawImage frame);
    NoiseFrameGenerator& from(const RawImages& frames);
    NoiseFrameGenerator& withAmplitude(Accumulator amplitude);
    RawImages build();
private:
    typedef boost::uniform_int<Accumulator> Distribution;
    boost::mt19937 rng;
    unsigned frameCount;
    RawImages inputFrames;
    Accumulator noiseAmplitude;

    RawImage generateNoisyFrame(const RawImage& inputFrame);
    RawPixel addNoise(RawPixel p, const Distribution& dist);
};

}

#endif // NEBULA_NOISEFRAMEGENERATOR_HPP
