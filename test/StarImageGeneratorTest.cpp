#include <gtest/gtest.h>
#include "StarImageGenerator.hpp"

struct StarImageGeneratorTest : testing::Test
{
    RawImage image;

    void expectPixels(int count, RawPixel color)
    {
        auto v = const_view(image);
        EXPECT_EQ(count, std::count(v.begin(), v.end(), color));
    }

    void expectBlackPixels(int count)
    {
        expectPixels(count, Color::black());
    }

    void expectBlackImage()
    {
        expectBlackPixels(image.width() * image.height());
    }

    void expectPixelsWithLuminance(int count, unsigned luminance)
    {
        expectPixels(count, Color::luminance(luminance));
    }

    void expectWhitePixelAt(unsigned x, unsigned y)
    {
        EXPECT_EQ(Color::white(), view(image)(x, y))
            << "expected white pixel at (" << x << ", " << y << ")";
    }
};

TEST_F(StarImageGeneratorTest, shouldOutputBlackImageWhenGivenNoStars)
{
    image = StarImageGenerator(17, 35).withStars({}).build();

    EXPECT_EQ(17, image.width());
    EXPECT_EQ(35, image.height());
    expectBlackImage();
}

TEST_F(StarImageGeneratorTest, shouldPutWhitePixelForAStarOnABlackBackground)
{
    image = StarImageGenerator(10, 10).withStars({ { 4, 5 } }).build();

    expectWhitePixelAt(4, 5);
    expectBlackPixels(99);
}

TEST_F(StarImageGeneratorTest, shouldPutWhitePixelForEachStar)
{
    image = StarImageGenerator(10, 10).withStars({ { 1, 7 }, { 8, 2 }, { 5, 4 } }).build();

    expectWhitePixelAt(1, 7);
    expectWhitePixelAt(8, 2);
    expectWhitePixelAt(5, 4);
}

TEST_F(StarImageGeneratorTest, shouldOutputImageWithGivenBackgroundLuminance)
{
    image = StarImageGenerator(10, 10).withBackgroundLuminance(45).withStars({ { 8, 6 } }).build();

    expectPixelsWithLuminance(99, 45);
}
