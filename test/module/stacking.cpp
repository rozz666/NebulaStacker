#include <gtest/gtest.h>
#include <Nebula/ApplicationFixture.hpp>
#include <Nebula/FrameFiles.hpp>
#include <Nebula/StarImageGenerator.hpp>
#include <Nebula/NoiseFrameGenerator.hpp>
#include <Nebula/translatedFrames.hpp>

namespace Nebula
{

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

TEST_F(ModuleTest, stack_many_frames_to_reduce_noise)
{
    auto STANDARD_FRAME = frameWithStarsAndBackgroundLuminance(16);
    auto FRAMES_WITH_NOISE = genNoise.frames(17).from(STANDARD_FRAME).withAmplitude(8).build();
    auto FRAMES_WITH_NOISE_LIST = frameFiles.writeFrames(FRAMES_WITH_NOISE);
    
    application.stack(FRAMES_WITH_NOISE_LIST, OUTPUT_IMAGE);
    
    frameFiles.expectAverageDifference(STANDARD_FRAME, OUTPUT_IMAGE, 1.0);
}

TEST_F(ModuleTest, DISABLED_stack_moved_frames)
{
    auto STANDARD_FRAME = frameWithStarsAndBackgroundLuminance(16);
    auto TRANSLATED_FRAMES = translatedFrames(STANDARD_FRAME, {
        {  -9,   5 }, {  14,   7 }, { -16,   3 }, {  -8,   5 },
        {  11,  -8 }, { -12, -10 }, {   3, -11 }, {   1, -14 },
        {  11,   7 }, {  12,   4 }, {   4,  -6 }, { -13, -10 },
        {   8,   3 }, {   6,   0 }, {   6,  12 }, { -14,   7 },
        { -10,   8 }, {   4, -15 }, {   1,  12 }, {  -3, -10 },
        {  12,  12 }, {  16,  -2 }, {  10,   2 }, {   4, -13 },
        { -10,  -4 }, {  16,   9 }, {  -5,   8 }, {   6,  13 },
        {   0,   3 }, {  -2,  -2 }, {   5,   3 }, {  -1,   5 }
    });
    auto FRAMES = genNoise.from(TRANSLATED_FRAMES).withAmplitude(8).build();
    auto FRAME_LIST = frameFiles.writeFrames(FRAMES);

    application.stack(FRAME_LIST, OUTPUT_IMAGE);

    frameFiles.expectAverageDifference(STANDARD_FRAME, OUTPUT_IMAGE, 1.5);
}

}
