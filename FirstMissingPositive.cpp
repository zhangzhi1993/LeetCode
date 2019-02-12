/*
要求O(N)时间，所以不能使用sort，后者最低也是Nlog(N)
*/

#include <vector>
#include <iostream>
#include "PrintUtils.cpp"
#include <algorithm>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool isContainesOne = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.at(i) == 1)
            {
                isContainesOne = true;
            }
            if (nums.at(i) < 1 || nums.at(i) > nums.size())
            {
                nums[i] = 1;
            }
        }
        if (!isContainesOne)
            return 1;
        if (nums.size() == 1)
        {
            return 2;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int a = abs(nums.at(i))-1;
            nums[a] = -abs(nums[a]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums.at(i) > 0)
                return i+1;
        }
        return nums.size()+1;
    }

};


int main(int argc, char const *argv[])
{
    vector<int> vec = {0,2,2,4,0,3,2,4,0};
    Solution sol;
    PrintUtils::printf(sol.firstMissingPositive(vec));
    getchar();
    return 0;
}