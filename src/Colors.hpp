#ifndef COLORS_HPP
#define COLORS_HPP
#include <boost/gil/typedefs.hpp>

typedef boost::gil::rgb16_pixel_t RawPixel;

namespace Color
{

inline RawPixel black() { return RawPixel(0, 0, 0); }
inline RawPixel white() { return RawPixel(65535, 65535, 65535); }

};

#endif // COLORS_HPP
