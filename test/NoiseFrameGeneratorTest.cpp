#include <gtest/gtest.h>
#include "NoiseFrameGenerator.hpp"

struct NoiseFrameGeneratorTest : testing::Test
{
    RawImage img;
    NoiseFrameGenerator generator;
    RawChannel LUMINANCE;

    NoiseFrameGeneratorTest() : img(32, 32)
    {
        LUMINANCE = 64;
        fill_pixels(view(img), Color::luminance(LUMINANCE));
    }

    static Accumulator channelSum(RawPixel p)
    {
        Accumulator sum = 0;
        static_for_each(p, [&sum](RawChannel ch) { sum += Accumulator(ch); });
        return sum;
    }
    
    static float channelVariance(RawPixel p, float mean)
    {
        float s = 0;
        static_for_each(p, [&s, mean](RawChannel ch) { s += (ch - mean) * (ch - mean); });
        return s / boost::gil::num_channels<RawPixel>::value;
    }

    RawChannel averageLuminance(const RawImage& frame)
    {
        auto v = const_view(frame);
        Accumulator sum = std::accumulate(v.begin(), v.end(), Accumulator(0), [&](Accumulator val, RawPixel p)
        {
            return val + channelSum(p);
        });
        return sum / (frame.width() * frame.height() * boost::gil::num_channels<RawPixel>::value);
    }

    float variance(const RawImage& frame)
    {
        float mean = averageLuminance(frame);
        auto v = const_view(frame);
        float sum = std::accumulate(v.begin(), v.end(), float(0), [&](float val, RawPixel p)
        {
            return val + channelVariance(p, mean);
        });
        return sum / (frame.width() * frame.height());
    }
};

TEST_F(NoiseFrameGeneratorTest, shouldGenerateGivenNumberOfFrames)
{
    generator.from(img);
    ASSERT_EQ(10u, generator.frames(10).build().size());
    ASSERT_EQ(7u, generator.frames(7).build().size());
}

TEST_F(NoiseFrameGeneratorTest, shouldAddNoNoiseWhenAmplitudeIsZero)
{
    auto frames = generator.from(img).frames(1).withAmplitude(0).build();
    ASSERT_TRUE(frames[0] == img);
}

TEST_F(NoiseFrameGeneratorTest, shouldAddUniformNoiseWithGivenAmplitude)
{
    Accumulator AMPLITUDE = 6;
    auto frame = generator.from(img).frames(1).withAmplitude(6).build()[0];
    ASSERT_NEAR(averageLuminance(frame), LUMINANCE, 1);
    float NUM_VALUES = AMPLITUDE * 2 + 1;
    float VARIANCE = (NUM_VALUES * NUM_VALUES + 1) / 12;
    ASSERT_NEAR(variance(frame), VARIANCE, 1) << "should be discrete uniform distribution";
}