#include <gtest/gtest.h>
#include "ApplicationFixture.hpp"
#include "FrameFiles.hpp"
#include "StarImageGenerator.hpp"
#include "NoiseFrameGenerator.hpp"

struct ModuleTest : testing::Test
{
    ApplicationFixture application;
    FrameFiles frameFiles;
    StarImageGenerator genImage;
    NoiseFrameGenerator genNoise;
    const std::string OUTPUT_IMAGE;

    ModuleTest()
        : genImage(128, 128), OUTPUT_IMAGE("output.tif") { }

    RawImage frameWithStars()
    {
        return genImage
            .withStars({ { 3, 7 }, { 102, 30 }, { 22, 11 } })
            .build();
    }
    
    RawImage frameWithStarsAndBackgroundLuminance(unsigned luminance)
    {
        return genImage
            .withBackgroundLuminance(luminance)
            .withStars({ { 10, 10 }, { 10, 118 }, { 118, 10 }, { 118, 118 } })
            .build();
    }
};

TEST_F(ModuleTest, stack_one_frame)
{
    RawImages ONE_LIGHT_FRAME = { frameWithStars() };
    auto ONE_LIGHT_FRAME_LIST = frameFiles.writeFrames(ONE_LIGHT_FRAME);
    application.stack(ONE_LIGHT_FRAME_LIST, OUTPUT_IMAGE);
    frameFiles.expectIdenticalImages(ONE_LIGHT_FRAME_LIST[0], OUTPUT_IMAGE);
}

TEST_F(ModuleTest, DISABLED_stack_many_frames_to_reduce_noise)
{
    auto STANDARD_FRAME = frameWithStarsAndBackgroundLuminance(16);
    auto FRAMES_WITH_NOISE = genNoise.frames(32).from(STANDARD_FRAME).withAmplitude(8).build();
    auto FRAMES_WITH_NOISE_LIST = frameFiles.writeFrames(FRAMES_WITH_NOISE);
    
    application.stack(FRAMES_WITH_NOISE_LIST, OUTPUT_IMAGE);
    
    frameFiles.expectAverageDifference(STANDARD_FRAME, OUTPUT_IMAGE, 0.5f);
}