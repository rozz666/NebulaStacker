#ifndef COLORS_HPP
#define COLORS_HPP
#include <boost/gil/typedefs.hpp>

typedef boost::gil::rgb16_pixel_t RawPixel;
typedef boost::gil::gray16_pixel_t RawGrayPixel;
typedef boost::gil::channel_type<RawPixel>::type RawChannel;
typedef std::int32_t Accumulator;

namespace Color
{

inline RawPixel black() { return RawPixel(0, 0, 0); }
inline RawPixel white() { return RawPixel(65535, 65535, 65535); }
inline RawPixel luminance(boost::gil::channel_type<RawPixel>::type value) { return RawPixel(value, value, value); }

};

#endif // COLORS_HPP
