#ifndef IMAGES_HPP
#define IMAGES_HPP

#include <vector>
#include <boost/gil/image.hpp>
#include <Colors.hpp>

typedef boost::gil::image<RawPixel> RawImage;
typedef std::vector<RawImage> RawImages;

typedef boost::gil::image<AccumPixel> AccumImage;

#endif // IMAGES_HPP
