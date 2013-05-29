#include <gtest/gtest.h>
#include "StarImageGenerator.hpp"

struct StarImageGeneratorTest : testing::Test
{
    void expectBlackPixelsOnImage(int count, const RawImage& img)
    {
        auto v = const_view(img);
        EXPECT_EQ(count, std::count(v.begin(), v.end(), Color::black()));
    }

    void expectBlackImage(const RawImage& img)
    {
        expectBlackPixelsOnImage(img.width() * img.height(), img);
    }
};

TEST_F(StarImageGeneratorTest, shouldOutputBlackImageWhenGivenNoStars)
{
    RawImage img = StarImageGenerator(17, 35).withStars({});

    EXPECT_EQ(17, img.width());
    EXPECT_EQ(35, img.height());
    expectBlackImage(img);
}

TEST_F(StarImageGeneratorTest, shouldPutWhitePixelForAStarOnABlackBackground)
{
    RawImage img = StarImageGenerator(10, 10).withStars({ { 4, 5 } });

    EXPECT_EQ(Color::white(), view(img)(4, 5));
    expectBlackPixelsOnImage(99, img);
}
