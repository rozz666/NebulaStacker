#include "NoiseFrameGenerator.hpp"
#include <boost/random/uniform_int.hpp>

NoiseFrameGenerator& NoiseFrameGenerator::frames(unsigned count)
{
    frameCount = count;
    return *this;
}

NoiseFrameGenerator& NoiseFrameGenerator::from(RawImage frame)
{
    this->frame = frame;
    return *this;
}

NoiseFrameGenerator& NoiseFrameGenerator::withAmplitude(Accumulator amplitude)
{
    noiseAmplitude = amplitude;
    return *this;
}

RawChannel addSat(RawChannel ch, Accumulator value)
{
    return std::min<Accumulator>(
        std::numeric_limits<RawChannel>::max(),
        std::max<Accumulator>(
            std::numeric_limits<RawChannel>::min(),
            Accumulator(ch) + value));
}

RawImages NoiseFrameGenerator::build()
{
    boost::mt19937 rng;
    boost::uniform_int<Accumulator> dist(-noiseAmplitude, noiseAmplitude);
    RawImage noisyFrame(frame.dimensions());
    transform_pixels(const_view(frame), view(noisyFrame), [&dist, &rng](RawPixel p)
    {
        RawPixel out = p;
        static_for_each(out, [&dist, &rng](RawChannel& ch)
        {
            ch = addSat(ch, dist(rng));
        });
        return out;
    });
    return RawImages(frameCount, noisyFrame);
}
