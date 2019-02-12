#include <iostream>
#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> abc = nums;
        int nLeft = 0;
        int nRight = abc.size() - 1;
        sort(abc.begin(), abc.end());
        while (nLeft < nRight)
        {
            int nSum = abc.at(nLeft) + abc.at(nRight);
            if (nSum > target)
                nRight--;
            else if (nSum < target)
                nLeft++;
            else
            {
                break;
            }
        } 
        vector<int> vecRes;
        vecRes.push_back(find(nums.begin(), nums.end(), abc.at(nLeft)) - nums.begin());
        vecRes.push_back(nums.rend() - find(nums.rbegin(), nums.rend(), abc.at(nRight)) - 1);
        return vecRes;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {3, 3};
    int target = 6;
    // vector<int> vec = {3, 2, 4};
    // int target = 6;
    // vector<int> vec = {2, 7};
    // int target = 9;
    Solution sol;
    PrintUtils::printf(sol.twoSum(vec, target));
    getchar();
    return 0;
}