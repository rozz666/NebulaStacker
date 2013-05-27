#ifndef STARIMAGEGENERATOR_HPP
#define STARIMAGEGENERATOR_HPP

#include <Images.hpp>
#include <Point.hpp>

class StarImageGenerator
{
public:
    StarImageGenerator(unsigned width, unsigned height) {}
    RawImage withStars(std::vector<Point> stars) { return RawImage(); }
};

#endif // STARIMAGEGENERATOR_HPP
