#include "StarImageGenerator.hpp"

StarImageGenerator& StarImageGenerator::withStars(Points stars)
{
    this->stars = stars;
    return *this;
}

void StarImageGenerator::putStarsOnImage(RawImage& img) const
{
    auto v = view(img);
    for (auto s : stars)
        v(s.x, s.y) = Color::white();
}

StarImageGenerator& StarImageGenerator::withBackgroundLuminance(unsigned luminance)
{
    backgroundColor = Color::luminance(luminance);
    return *this;
}

RawImage StarImageGenerator::build() const
{
    RawImage img(width, height, backgroundColor, 0);
    putStarsOnImage(img);
    return img;
}
