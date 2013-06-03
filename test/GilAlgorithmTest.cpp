#include <GilAlgorithm.hpp>
#include <gtest/gtest.h>
#include <boost/gil/typedefs.hpp>
#include <boost/gil/image.hpp>

using namespace boost::gil;

TEST(for_each_channel_accumulate_test, should_call_functor_for_each_channel_in_parallel_in_both_images_and_sum_the_results)
{
    rgb16_image_t img1(1, 1);
    rgb8_image_t img2(1, 1);

    view(img1)(0, 0) = rgb16_pixel_t(1025, 18, 36);
    view(img2)(0, 0) = rgb8_pixel_t(1, 2, 4);

    typedef boost::gil::channel_type<decltype(img1)>::type channel1_t;
    typedef boost::gil::channel_type<decltype(img2)>::type channel2_t;

    ASSERT_EQ(1024 + 16 + 32, for_each_channel_accumulate(const_view(img1), const_view(img2), 0, [&](channel1_t p1, channel2_t p2)
    {
        return p1 - p2;
    })) << "should sum all results";
}

TEST(for_each_channel_accumulate_test, should_call_functor_for_each_pixel_in_parallel_in_both_images)
{
    rgb16_image_t img1(3, 2), img2(3, 2);
    auto v1 = view(img1), v2 = view(img2);

    v1(0, 0) = rgb16_pixel_t(1, 0, 0); v1(1, 0) = rgb16_pixel_t(2, 0, 0);  v1(2, 0) = rgb16_pixel_t(4, 0, 0);
    v1(0, 1) = rgb16_pixel_t(8, 0, 0); v1(1, 1) = rgb16_pixel_t(16, 0, 0); v1(2, 1) = rgb16_pixel_t(32, 0, 0);
    v2(0, 0) = rgb16_pixel_t(64, 0, 0);  v2(1, 0) = rgb16_pixel_t(128, 0, 0);  v2(2, 0) = rgb16_pixel_t(256, 0, 0);
    v2(0, 1) = rgb16_pixel_t(512, 0, 0); v2(1, 1) = rgb16_pixel_t(1024, 0, 0); v2(2, 1) = rgb16_pixel_t(2048, 0, 0);

    typedef boost::gil::channel_type<decltype(img1)>::type channel_t;

    ASSERT_EQ(4095, for_each_channel_accumulate(const_view(img1), const_view(img2), 0, [&](channel_t p1, channel_t p2)
    {
        return p1 + p2;
    })) << "should call functor for each pixel";
}

TEST(for_each_channel_accumulate_test, should_include_the_initial_value)
{
    rgb16_image_t img1(1, 1), img2(1, 1);

    view(img1)(0, 0) = rgb16_pixel_t(1, 0, 0);
    view(img2)(0, 0) = rgb16_pixel_t(1, 0, 0);

    typedef boost::gil::channel_type<decltype(img1)>::type channel1_t;
    typedef boost::gil::channel_type<decltype(img2)>::type channel2_t;

    ASSERT_EQ(2 + 8, for_each_channel_accumulate(const_view(img1), const_view(img2), 8, [&](channel1_t p1, channel2_t p2)
    {
        return p1 + p2;
    }));
}