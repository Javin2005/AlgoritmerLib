#ifndef CLOSEST_POINT_HPP
#define CLOSEST_POINT_HPP

#include <vector>
#include <cmath>
#include <ostream>

namespace DivideAndConquer
{
    struct Point
    {
        double x, y;
        double distanceTo(Point other) const
        {
            return std::hypot(other.x - x, other.y - y);
        }
    };

    inline std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    struct ClosestResult
    {
        Point p1;
        Point p2;
        double dist;
    };

    ClosestResult solveClosestPoints(const std::vector<Point> &points);

}
#endif