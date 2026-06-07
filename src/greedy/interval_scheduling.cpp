#include "interval_scheduling.hpp"
#include <algorithm>

using namespace std;

namespace Greedy
{
    vector<Interval> solveIntervalScheduling(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b)
             { return a.end < b.end; });

        vector<Interval> selected;

        selected.push_back(intervals[0]);
        int lastEndTime = intervals[0].end;

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start >= lastEndTime)
            {
                selected.push_back(intervals[i]);
                lastEndTime = intervals[i].end;
            }
        }
        return selected;
    }

}