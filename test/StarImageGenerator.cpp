#include "StarImageGenerator.hpp"

RawImage StarImageGenerator::withStars(std::vector<Point> stars)
{
    RawImage img(width, height, Color::black(), 0);
    if (stars.empty())
        return img;
    view(img)(stars[0].x, stars[0].y) = Color::white();
    return img;
}
