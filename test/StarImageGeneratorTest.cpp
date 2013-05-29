#include <gtest/gtest.h>
#include "StarImageGenerator.hpp"

struct StarImageGeneratorTest : testing::Test
{
    void expectBlackImage(const RawImage& img)
    {
        auto v = boost::gil::const_view(img);
        EXPECT_EQ(img.width() * img.height(), std::count(v.begin(), v.end(), RawPixel(0, 0, 0)))
            << "not all pixels are black";
    }
};

TEST_F(StarImageGeneratorTest, shouldOutputBlackImageWhenGivenNoStars)
{
    RawImage img = StarImageGenerator(17, 35).withStars({});

    EXPECT_EQ(17, img.width());
    EXPECT_EQ(35, img.height());
    expectBlackImage(img);
}