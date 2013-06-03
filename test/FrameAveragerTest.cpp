#include "FrameAverager.hpp"
#include <gtest/gtest.h>
#include "RawImagePrinter.hpp"

struct FrameAveragerTest : testing::Test
{
    FrameAverager averager;
};

TEST_F(FrameAveragerTest, shouldReturnEmptyImageWhenNoFramesAreAdded)
{
    ASSERT_EQ(0u, const_view(averager.getCombinedFrame()).size());
}

TEST_F(FrameAveragerTest, shouldReturnOriginalFrameWhenOnlyOneIsAdded)
{
    RawImage img(5, 7);
    fill_pixels(view(img), Color::luminance(20));
    averager.addFrame(img);
    ASSERT_TRUE(img == averager.getCombinedFrame());
}

TEST_F(FrameAveragerTest, shouldReturnAverageOfAllAddedFrames)
{
    RawImage img1(2, 1), img2(2, 1), img3(2, 1), expected(2, 1);
    auto v1 = view(img1), v2 = view(img2), v3 = view(img3), e = view(expected);

    v1(0, 0) = { 0, 1, 10 }; v1(1, 0) = { 65535, 65534, 0 };
    v2(0, 0) = { 0, 2, 10 }; v2(1, 0) = { 65535, 65533, 1 };
    v3(0, 0) = { 0, 3, 10 }; v3(1, 0) = { 65535, 65532, 65533 };

    e(0, 0) = { 0, 2, 10 }; e(1, 0) = { 65535, 65533, 65534 / 3 };

    averager.addFrame(img1);
    averager.addFrame(img2);
    averager.addFrame(img3);

    ASSERT_EQ(expected, averager.getCombinedFrame());
}