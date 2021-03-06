#ifndef NEBULA_IMAGES_HPP
#define NEBULA_IMAGES_HPP

#include <vector>
#include <boost/gil/image.hpp>
#include <Nebula/Colors.hpp>

namespace Nebula
{

typedef boost::gil::image<RawPixel> RawImage;
typedef std::vector<RawImage> RawImages;

typedef boost::gil::image<AccumPixel> AccumImage;

}

#endif // NEBULA_IMAGES_HPP
