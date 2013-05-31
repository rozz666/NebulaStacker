#include <gtest/gtest.h>
#include "NoiseFrameGenerator.hpp"

TEST(NoiseFrameGeneratorTest, shouldGenerateGivenNumberOfFrames)
{
    RawImage img(16, 16);
    fill_pixels(view(img), Color::luminance(64));
    NoiseFrameGenerator ng;
    ng.from(img);
    ASSERT_EQ(10u, ng.frames(10).build().size());
    ASSERT_EQ(7u, ng.frames(7).build().size());
}

TEST(NoiseFrameGeneratorTest, shouldAddNoNoiseWhenAmplitudeIsZero)
{
    RawImage img(16, 16);
    fill_pixels(view(img), Color::luminance(64));
    NoiseFrameGenerator ng;
    auto frames = ng.from(img).frames(1).withAmplitude(0).build();
    ASSERT_TRUE(frames[0] == img);
}
