#ifndef STARIMAGEGENERATOR_HPP
#define STARIMAGEGENERATOR_HPP

#include <Nebula/Images.hpp>
#include <Nebula/Point.hpp>
#include <Nebula/Colors.hpp>

namespace Nebula
{

class StarImageGenerator
{
public:
    StarImageGenerator(unsigned width, unsigned height)
        : width(width), height(height), backgroundColor(Color::black()) {}
    StarImageGenerator& withStars(Points stars);
    StarImageGenerator& withBackgroundLuminance(unsigned luminance);
    RawImage build() const;
private:
    unsigned width, height;
    Points stars;
    RawPixel backgroundColor;
    void putStarsOnImage(RawImage& img) const;
};

}

#endif // STARIMAGEGENERATOR_HPP
