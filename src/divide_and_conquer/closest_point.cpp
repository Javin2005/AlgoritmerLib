#include "closest_point.hpp"

#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

namespace DivideAndConquer
{

    const double INF = numeric_limits<double>::max();

    ClosestResult stripCheck(vector<Point> strip, ClosestResult minimum)
    {
        ClosestResult res = minimum;

        sort(strip.begin(), strip.end(), [](Point &a, Point &b)
             { return a.y < b.y; });

        for (int i = 0; i < strip.size(); i++)
        {

            for (int j = i + 1; j < strip.size() && j <= i + 7; j++)
            {
                double d = strip[i].distanceTo(strip[j]);
                if (d < res.dist)
                {
                    res.dist = d;
                    res.p1 = strip[i];
                    res.p2 = strip[j];
                }
            }
        }

        return res;
    }

    ClosestResult findClosest(const vector<Point> &xSortedPoints)
    {

        ClosestResult res;

        if (xSortedPoints.size() < 3)
        {
            res.dist = INF;
            for (int i = 0; i < xSortedPoints.size(); i++)
            {
                for (int j = i + 1; j < xSortedPoints.size(); j++)
                {
                    double dist = xSortedPoints[i].distanceTo(xSortedPoints[j]);
                    if (dist < res.dist)
                    {
                        res.p1 = xSortedPoints[i];
                        res.p2 = xSortedPoints[j];
                        res.dist = dist;
                    }
                }
            }
            return res;
        }

        int mid = xSortedPoints.size() / 2;
        double midX = xSortedPoints[mid].x;

        vector<Point> left(xSortedPoints.begin(), xSortedPoints.begin() + mid);
        vector<Point> right(xSortedPoints.begin() + mid, xSortedPoints.end());

        ClosestResult resL = findClosest(left);
        ClosestResult resR = findClosest(right);
        ClosestResult minimum = (resL.dist < resR.dist) ? resL : resR;

        vector<Point> strip;
        for (auto &p : xSortedPoints)
        {
            if ((abs(p.x - midX) < minimum.dist))
            {
                strip.push_back(p);
            }
        }

        return stripCheck(strip, minimum);
    }

    ClosestResult solveClosestPoints(const vector<Point> &points)
    {
        vector<Point> ps(points);
        ClosestResult res;
        sort(ps.begin(), ps.end(), [](Point &a, Point &b)
             { return a.x < b.x; });

        return findClosest(ps);
    }

}