#ifndef COLORS_HPP
#define COLORS_HPP
#include <boost/gil/typedefs.hpp>
#include <boost/cstdint.hpp>

typedef boost::gil::rgb16_pixel_t RawPixel;
typedef boost::gil::gray16_pixel_t RawGrayPixel;
typedef boost::gil::channel_type<RawPixel>::type RawChannel;
typedef boost::int32_t Accumulator;

typedef boost::gil::rgb32s_pixel_t AccumPixel;

namespace Color
{

inline RawPixel black() { return RawPixel(0, 0, 0); }
inline RawPixel white() { return RawPixel(65535, 65535, 65535); }
inline RawPixel luminance(boost::gil::channel_type<RawPixel>::type value) { return RawPixel(value, value, value); }

};

#endif // COLORS_HPP
