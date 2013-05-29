#ifndef IMAGES_HPP
#define IMAGES_HPP

#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>

typedef boost::gil::rgb16_pixel_t RawPixel;
typedef boost::gil::image<RawPixel> RawImage;
typedef std::vector<RawImage> RawImages;

#endif // IMAGES_HPP
