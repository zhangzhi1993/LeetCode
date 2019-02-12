#include <iostream>
#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1)
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        return innerSearch(nums, target, left, right);
    }

    int innerSearch(vector<int>& nums, int target, int left, int right)
    {
        if ((left+1) >= right)
        {
            if (nums.at(left) == target)
                return left;
            else if (nums.at(right) == target)
                return right;
            else
            {
                return -1;
            }
        }
        int nMid = (left + right) / 2;
        if (nums.at(nMid) > nums.at(left))
        {
            if (nums.at(nMid) >= target && nums.at(left) <= target)
            {
                return innerSearch(nums, target, left, nMid);
            }
            else
            {
                return innerSearch(nums, target, nMid, right);
            }
        }
        else
        {
            if (nums.at(nMid) <= target && nums.at(right) >= target)
            {
                return innerSearch(nums, target, nMid, right);
            }
            else
            {
                return innerSearch(nums, target, left, nMid);
            }
            
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {4,5,6,1,2,3};
    int target = 1;
    Solution sol;
    PrintUtils::printf(sol.search(vec, target));
    getchar();
    return 0;
}