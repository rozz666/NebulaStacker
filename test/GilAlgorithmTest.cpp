#include <GilAlgorithm.hpp>
#include <gtest/gtest.h>
#include <boost/gil/typedefs.hpp>
#include <boost/gil/image.hpp>

using namespace boost::gil;

struct for_each_channel_accumulate_test : testing::Test
{
    typedef boost::gil::channel_type<rgb8_image_t>::type channel8_t;
    typedef boost::gil::channel_type<rgb16_image_t>::type channel16_t;
};

TEST_F(for_each_channel_accumulate_test, should_call_functor_for_each_channel_in_parallel_in_both_images_and_sum_the_results)
{
    rgb16_image_t img1(1, 1);
    rgb8_image_t img2(1, 1);

    view(img1)(0, 0) = { 1025, 18, 36 };
    view(img2)(0, 0) = { 1, 2, 4 };

    ASSERT_EQ(1024 + 16 + 32, for_each_channel_accumulate(const_view(img1), const_view(img2), 0, [&](channel16_t p1, channel8_t p2)
    {
        return p1 - p2;
    })) << "should sum all results";
}

TEST_F(for_each_channel_accumulate_test, should_call_functor_for_each_pixel_in_parallel_in_both_images)
{
    rgb16_image_t img1(3, 2), img2(3, 2);
    auto v1 = view(img1), v2 = view(img2);

    v1(0, 0) = { 1, 0, 0 }; v1(1, 0) = { 2, 0, 0 };  v1(2, 0) = { 4, 0, 0 };
    v1(0, 1) = { 8, 0, 0 }; v1(1, 1) = { 16, 0, 0 }; v1(2, 1) = { 32, 0, 0 };
    v2(0, 0) = { 64, 0, 0 };  v2(1, 0) = { 128, 0, 0 };  v2(2, 0) = { 256, 0, 0 };
    v2(0, 1) = { 512, 0, 0 }; v2(1, 1) = { 1024, 0, 0 }; v2(2, 1) = { 2048, 0, 0 };

    ASSERT_EQ(4095, for_each_channel_accumulate(const_view(img1), const_view(img2), 0, [&](channel16_t p1, channel16_t p2)
    {
        return p1 + p2;
    })) << "should call functor for each pixel";
}

TEST_F(for_each_channel_accumulate_test, should_include_the_initial_value)
{
    rgb16_image_t img1(1, 1), img2(1, 1);

    view(img1)(0, 0) = { 1, 0, 0 };
    view(img2)(0, 0) = { 1, 0, 0 };

    ASSERT_EQ(2 + 8, for_each_channel_accumulate(const_view(img1), const_view(img2), 8, [&](channel16_t p1, channel16_t p2)
    {
        return p1 + p2;
    }));
}

TEST_F(for_each_channel_accumulate_test, should_return_initial_value_for_empty_images)
{
    rgb16_image_t img1, img2;

    ASSERT_EQ(8, for_each_channel_accumulate(const_view(img1), const_view(img2), 8, [&](channel16_t p1, channel16_t p2)
    {
        return 10;
    }));
}
