#include "StarImageGenerator.hpp"

RawImage StarImageGenerator::withStars(std::vector<Point> stars)
{
    RawImage img(width, height, Color::black(), 0);
    putStarsOnImage(stars, img);
    return img;
}

void StarImageGenerator::putStarsOnImage(const std::vector<Point>& stars, RawImage& img)
{
    auto v = view(img);
    for (auto s : stars)
        v(s.x, s.y) = Color::white();
}

StarImageGenerator& StarImageGenerator::withBackgroundLuminance(unsigned luminance)
{
    return *this;
}
