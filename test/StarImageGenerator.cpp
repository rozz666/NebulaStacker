#include "StarImageGenerator.hpp"

RawImage StarImageGenerator::withStars(std::vector< Point > stars)
{
    return RawImage(width, height, RawPixel(0, 0, 0), 0);
}
