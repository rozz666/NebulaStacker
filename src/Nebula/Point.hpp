#ifndef NEBULA_POINT_HPP
#define NEBULA_POINT_HPP

#include <vector>

namespace Nebula
{

struct Point
{
    int x, y;

    Point() : x(0), y(0) { }
    Point(int x, int y) : x(x), y(y) { }
};

typedef std::vector<Point> Points;

}

#endif // NEBULA_POINT_HPP
