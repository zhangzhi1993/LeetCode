#include <iostream>
#include <algorithm>
#include <vector>
#include "PrintUtils.cpp"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        return innerSearchInsert(nums, target, 0, nums.size()-1);
        
    }

    int innerSearchInsert(vector<int>& nums, int target, int left, int right)
    {
        if (left+1 >= right)
        {
            int nLeft = nums.at(left);
            int nRight = nums.at(right);
            if (nLeft == target)
            {
                return left;
            }
            if (nRight == target)
            {
                return right;
            }
            if (nLeft > target)
            {
                return left;
            }
            if (nRight < target)
            {
                return right+1;
            }
            if (nLeft < target && nRight > target)
            {
                return right;
            }
        }
        int mid = (left + right) / 2;
        if (nums.at(mid) == target)
        {
            return mid;
        }
        else if (nums.at(mid) < target)
        {
            return innerSearchInsert(nums, target, mid, right);
        }
        else
        {
            return innerSearchInsert(nums, target, left, mid-1);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {1,3,5,6};
    int target = 0;
    Solution sol;
    PrintUtils::printf(sol.searchInsert(vec, target));
    getchar();
    return 0;
}