#include "NoiseFrameGenerator.hpp"
#include <functional>

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

void addSat(RawChannel& ch, Accumulator value)
{
    ch = std::min<Accumulator>(
        std::numeric_limits<RawChannel>::max(),
        std::max<Accumulator>(
            std::numeric_limits<RawChannel>::min(),
            Accumulator(ch) + value));
}

RawPixel NoiseFrameGenerator::addNoise(RawPixel p, const Distribution& dist)
{
    auto& rng = this->rng;
    static_for_each(p, [&](RawChannel& ch) { addSat(ch, dist(rng)); });
    return p;
}


RawImage NoiseFrameGenerator::generateNoisyFrame()
{
    using std::placeholders::_1;
    boost::uniform_int<Accumulator> dist(-noiseAmplitude, noiseAmplitude);
    RawImage noisyFrame(frame.dimensions());
    transform_pixels(const_view(frame), view(noisyFrame), std::bind(&NoiseFrameGenerator::addNoise, this, _1, dist));
    return noisyFrame;
}

RawImages NoiseFrameGenerator::build()
{
    RawImages frames;
    frames.reserve(frameCount);
    std::generate_n(std::back_inserter(frames), frameCount, std::bind(&NoiseFrameGenerator::generateNoisyFrame, this));
    return frames;
}
