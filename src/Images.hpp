#ifndef IMAGES_HPP
#define IMAGES_HPP

#include <boost/gil/image.hpp>
#include <Colors.hpp>

typedef boost::gil::image<RawPixel> RawImage;
typedef std::vector<RawImage> RawImages;

#endif // IMAGES_HPP
