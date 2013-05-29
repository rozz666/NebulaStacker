#ifndef STARIMAGEGENERATOR_HPP
#define STARIMAGEGENERATOR_HPP

#include <Images.hpp>
#include <Point.hpp>

class StarImageGenerator
{
public:
    StarImageGenerator(unsigned width, unsigned height)
        : width(width), height(height) {}
    RawImage withStars(std::vector<Point> stars);
private:
    unsigned width, height;
    void putStarsOnImage(const std::vector<Point>& stars, RawImage& img);
};

#endif // STARIMAGEGENERATOR_HPP
