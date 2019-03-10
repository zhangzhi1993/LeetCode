#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        res.push_back(newInterval);
        for (int i = 0; i < intervals.size(); i++)
        {
            Interval a = res.at(0);
            Interval b = intervals.at(i);
            if (a.end >= b.start && a.start <= b.end)
            {
                Interval c;
                c.start = min(a.start, b.start);
                c.end = max(a.end, b.end);
                res[0] = c;
            }
            else
            {
                res.push_back(b);
            }
        }
        sort(res.begin(), res.end(), lessInterval);
        return res;
    }

    static bool lessInterval(Interval a, Interval b)
    {
        return a.start < b.start;
    }
};