#ifndef INTERVAL_SCHEDULING_HPP
#define INTERVAL_SCHEDULING_HPP

#include <vector>

namespace Greedy
{
    struct Interval
    {
        int start;
        int end;
        int id;
    };

    std::vector<Interval> solveIntervalScheduling(std::vector<Interval> &intervals);

}

#endif