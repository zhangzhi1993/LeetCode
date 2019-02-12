#include <iostream>
#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> pos = {-1, -1};
        if (nums.size() < 1)
        {
            return pos;
        }
        int left = 0;
        int right = nums.size() - 1;
        return innerSearch(nums, target, left, right, pos);
    }

    vector<int> innerSearch(vector<int>& nums, int target, int left, int right, vector<int> pos)
    {
        if ((left+1) >= right)
        {
            if (left >= 0 && nums.at(left) == target)
            {
                if (pos[0] == -1)
                    pos[0] = left;
                if (pos[1] == -1)
                    pos[1] = left;
                if (pos[0] > left)
                    pos[0] = left;
                if (pos[1] < left)
                    pos[1] = left;
            }
                
            if (right < nums.size() && nums.at(right) == target)
            {
                if (pos[0] == -1)
                    pos[0] = right;
                if (pos[1] == -1)
                    pos[1] = right;
                if (pos[0] > right)
                    pos[0] = right;
                if (pos[1] < right)
                    pos[1] = right;
            }
            return pos;
        }
        int nMid = (left + right) / 2;
        if (nums.at(nMid) == target)
        {
            if (nMid < pos[0] || pos[0] == -1)
                pos[0] = nMid;
            if (nMid > pos[1] || pos[1] == -1)
                pos[1] = nMid;
            pos[0] = innerSearch(nums, target, left, nMid-1, pos).at(0);
            pos[1] = innerSearch(nums, target, nMid+1, right, pos).at(1);
            return pos;
        }
        else if (nums.at(nMid) > target)
        {
            return innerSearch(nums, target, left, nMid-1, pos);
        }
        else
        {
            return innerSearch(nums, target, nMid+1, right, pos);  
        }
    }
};


int main(int argc, char const *argv[])
{
    // vector<int> vec = {1, 2, 3};
    // int target = 2;
    // vector<int> vec = {5,7,7,8,8,10};
    // int target = 6;
    vector<int> vec = {0,0,1,1,2,2,2,2,3,3,4,4,4,5,6,6,6,7,8,8};
    int target = 4;
    Solution sol;
    PrintUtils::printf(sol.searchRange(vec, target));
    getchar();
    return 0;
}