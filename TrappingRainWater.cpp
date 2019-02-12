#include <vector>
#include <iostream>
#include "PrintUtils.cpp"
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int nSize = height.size();
        if (nSize < 1)
            return 0;
        vector<int> maxLeft(nSize), maxRight(nSize);
        maxLeft[0] = height.at(0);
        maxRight[nSize-1] = height.at(nSize-1);
        for (int i = 1; i < nSize; i++)
        {
            maxLeft[i] = max(maxLeft.at(i-1), height.at(i));
            maxRight[nSize-i-1] = max(maxRight.at(nSize-i), height.at(nSize-i-1));
        }
        int area = 0;
        for (int i = 1; i < nSize-1; i++)
        {
            area += min(maxLeft.at(i), maxRight.at(i)) - height.at(i);
        }
        return area;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    PrintUtils::printf(sol.trap(vec));
    getchar();
    return 0;
}