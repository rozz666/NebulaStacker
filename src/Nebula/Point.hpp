#ifndef POINT_HPP
#define POINT_HPP

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

#endif // POINT_HPP
