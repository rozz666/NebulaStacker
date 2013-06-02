#include <numeric>
#include <gtest/gtest.h>
#include "NoiseFrameGenerator.hpp"

struct NoiseFrameGeneratorTest : testing::Test
{
    RawImage img;
    NoiseFrameGenerator generator;
    RawChannel LUMINANCE;
    Accumulator AMPLITUDE;

    NoiseFrameGeneratorTest() : img(16, 16)
    {
        LUMINANCE = 64;
        AMPLITUDE = 6;
        fill_pixels(view(img), Color::luminance(LUMINANCE));

        generator.from(img).withAmplitude(AMPLITUDE);
    }

    static Accumulator channelSum(RawPixel p)
    {
        Accumulator sum = 0;
        static_for_each(p, [&sum](RawChannel ch) { sum += Accumulator(ch); });
        return sum;
    }
    
    static double channelVariance(RawPixel p, double mean)
    {
        double s = 0;
        static_for_each(p, [&s, mean](RawChannel ch) { s += (ch - mean) * (ch - mean); });
        return s / boost::gil::num_channels<RawPixel>::value;
    }

    double averageLuminance(const RawImage& frame)
    {
        auto v = const_view(frame);
        auto sum = std::accumulate(v.begin(), v.end(), double(0), [&](Accumulator val, RawPixel p)
        {
            return val + channelSum(p);
        });
        return sum / (frame.width() * frame.height() * boost::gil::num_channels<RawPixel>::value);
    }

    double variance(const RawImage& frame)
    {
        auto mean = averageLuminance(frame);
        auto v = const_view(frame);
        auto sum = std::accumulate(v.begin(), v.end(), double(0), [&](double val, RawPixel p)
        {
            return val + channelVariance(p, mean);
        });
        return sum / (frame.width() * frame.height());
    }

    void assertChannelsBetween(RawImage& frame, RawChannel lo, RawChannel hi)
    {
        //auto v = const_view(frame);
        for (auto p : const_view(frame))
        {
            static_for_each(p, [=](RawChannel ch)
            {
                ASSERT_GE(ch, lo);
                ASSERT_LE(ch, hi);
            });
        }
    }
};

TEST_F(NoiseFrameGeneratorTest, shouldGenerateGivenNumberOfFrames)
{
    ASSERT_EQ(10u, generator.frames(10).build().size());
    ASSERT_EQ(7u, generator.frames(7).build().size());
}

TEST_F(NoiseFrameGeneratorTest, shouldAddNoNoiseWhenAmplitudeIsZero)
{
    auto frames = generator.withAmplitude(0).build();
    ASSERT_TRUE(frames[0] == img);
}

TEST_F(NoiseFrameGeneratorTest, shouldAddUniformNoiseWithGivenAmplitude)
{
    auto frame = generator.build()[0];
    ASSERT_NEAR(averageLuminance(frame), LUMINANCE, 1);
    double NUM_VALUES = AMPLITUDE * 2 + 1;
    double VARIANCE = (NUM_VALUES * NUM_VALUES - 1) / 12;
    ASSERT_NEAR(variance(frame), VARIANCE, 1) << "should be discrete uniform distribution";
}

TEST_F(NoiseFrameGeneratorTest, shouldNotUnderflowChannels)
{
    fill_pixels(view(img), Color::black());
    auto frame = generator.from(img).build()[0];
    assertChannelsBetween(frame, Color::black()[0], Color::black()[0] + AMPLITUDE);
}

TEST_F(NoiseFrameGeneratorTest, shouldNotOverflowChannels)
{
    fill_pixels(view(img), Color::white());
    auto frame = generator.from(img).build()[0];
    assertChannelsBetween(frame, Color::white()[0] - AMPLITUDE, Color::white()[0]);
}

TEST_F(NoiseFrameGeneratorTest, shouldGenerateDifferentFrames)
{
    auto frames1 = generator.frames(2).build();
    auto frames2 = generator.frames(1).build();
    ASSERT_TRUE(frames1[0] != frames1[1]);
    ASSERT_TRUE(frames1[0] != frames2[0]);
    ASSERT_TRUE(frames1[1] != frames2[0]);
}
