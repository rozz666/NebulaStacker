#ifndef IMAGES_HPP
#define IMAGES_HPP

#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>

typedef boost::gil::rgb16_image_t RawImage;
typedef RawImage::value_type RawPixel;
typedef std::vector<RawImage> RawImages;

#endif // IMAGES_HPP
