#include <gtest/gtest.h>
#include "ApplicationFixture.hpp"
#include "FrameFiles.hpp"
#include "StarImageGenerator.hpp"
#include <boost/gil/image.hpp>

struct ModuleTest : testing::Test
{
    ApplicationFixture application;
    FrameFiles frameFiles;
    Strings ONE_LIGHT_FRAME_LIST;
    StarImageGenerator genImage;
    std::vector<RawImage> ONE_LIGHT_FRAME;
    std::string OUTPUT_IMAGE;

    ModuleTest() : genImage(128, 128)
    {
        ONE_LIGHT_FRAME = { genImage.withStars({ { 3, 7 }, { 102, 30 }, { 22, 11 } }) };
        ONE_LIGHT_FRAME_LIST = { "light_frame_0.tif" };
        OUTPUT_IMAGE = "output.tif";
    }
};

TEST_F(ModuleTest, stack_one_frame)
{
    frameFiles.writeFrames(ONE_LIGHT_FRAME, ONE_LIGHT_FRAME_LIST);
    application.stack(ONE_LIGHT_FRAME_LIST, OUTPUT_IMAGE);
    frameFiles.expectIdenticalImages(ONE_LIGHT_FRAME[0], OUTPUT_IMAGE);
}