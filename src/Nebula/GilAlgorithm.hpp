#ifndef NEBULA_GILALGORITHM_HPP
#define NEBULA_GILALGORITHM_HPP
#include <boost/gil/color_base_algorithm.hpp>
#include <boost/gil/algorithm.hpp>
#include <stdexcept>

namespace Nebula
{

template <typename Result, typename View1, typename View2, typename Op2>
Result for_each_channel_accumulate(const View1& view1, const View2& view2, Result initial, Op2 op)
{
    if (view1.dimensions() != view2.dimensions())
        throw std::invalid_argument("for_each_channel_accumulate: view dimensions do not match");

    typedef typename boost::gil::channel_type<View1>::type channel1_t;
    typedef typename boost::gil::channel_type<View2>::type channel2_t;

    for (std::ptrdiff_t y = 0; y < view1.height(); ++y)
    {
        typename View1::x_iterator it1 = view1.row_begin(y);
        typename View2::x_iterator it2 = view2.row_begin(y);

        for (; it1 != view1.row_end(y); ++it1, ++it2)
        {
            boost::gil::static_for_each(*it1, *it2, [&](channel1_t left, channel2_t right) {
                initial = initial + op(left, right);
            });
        }
    }
    return initial;
}

}

#endif // NEBULA_GILALGORITHM_HPP
