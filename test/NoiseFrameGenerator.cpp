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

RawImage NoiseFrameGenerator::generateNoisyFrame()
{
    boost::uniform_int<Accumulator> dist(-noiseAmplitude, noiseAmplitude);
    RawImage noisyFrame(frame.dimensions());
    auto& rng = this->rng;
    transform_pixels(const_view(frame), view(noisyFrame), [&dist, &rng](RawPixel p) -> RawPixel // TODO: extract
    {
        RawPixel out = p;
        static_for_each(out, [&dist, &rng](RawChannel& ch)
        {
            ch = addSat(ch, dist(rng));
        });
        return out;
    });
    return noisyFrame;
}

RawImages NoiseFrameGenerator::build()
{
    RawImages frames;
    frames.reserve(frameCount);
    for (unsigned i = 0; i < frameCount; ++i)
        frames.push_back(generateNoisyFrame());
    return frames;
}
