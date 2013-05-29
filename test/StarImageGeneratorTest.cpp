#include <gtest/gtest.h>
#include "StarImageGenerator.hpp"

struct StarImageGeneratorTest : testing::Test
{
    RawImage image;
    
    void expectBlackPixels(int count)
    {
        auto v = const_view(image);
        EXPECT_EQ(count, std::count(v.begin(), v.end(), Color::black()));
    }

    void expectBlackImage()
    {
        expectBlackPixels(image.width() * image.height());
    }

    void expectWhitePixelAt(unsigned x, unsigned y)
    {
        EXPECT_EQ(Color::white(), view(image)(x, y))
            << "expected white pixel at (" << x << ", " << y << ")";
    }
};

TEST_F(StarImageGeneratorTest, shouldOutputBlackImageWhenGivenNoStars)
{
    image = StarImageGenerator(17, 35).withStars({});

    EXPECT_EQ(17, image.width());
    EXPECT_EQ(35, image.height());
    expectBlackImage();
}

TEST_F(StarImageGeneratorTest, shouldPutWhitePixelForAStarOnABlackBackground)
{
    image = StarImageGenerator(10, 10).withStars({ { 4, 5 } });

    expectWhitePixelAt(4, 5);
    expectBlackPixels(99);
}

TEST_F(StarImageGeneratorTest, shouldPutWhitePixelForEachStar)
{
    image = StarImageGenerator(10, 10).withStars({ { 1, 7 }, { 8, 2 }, { 5, 4 } });

    expectWhitePixelAt(1, 7);
    expectWhitePixelAt(8, 2);
    expectWhitePixelAt(5, 4);
}
