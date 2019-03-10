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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() < 1)
            return res;
        if (intervals.size() < 2)
            return intervals;
        sort(intervals.begin(), intervals.end(), lessInterval);
        res.push_back(intervals.at(0));
        for (int i = 1; i < intervals.size(); i++)
        {
            Interval a = res.at(res.size()-1);
            Interval b = intervals.at(i);
            if (a.end >= b.start)
            {
                Interval c;
                c.start = a.start;
                c.end = max(a.end, b.end);
                res[res.size()-1] = c;
            }
            else
            {
                res.push_back(b);
            }
            
        }
        return res;
    }
    static bool lessInterval(Interval a, Interval b)
    {
        return a.start < b.start;
    }
};

