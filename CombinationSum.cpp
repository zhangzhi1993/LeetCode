#include <vector>
#include <iostream>
#include "PrintUtils.cpp"
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        if (candidates.size() == 0)
            return res;
        vector<int> nums;
        findRes(candidates, nums, 0, target);
        return res;
    }

    void findRes(vector<int>& candidates, vector<int> &nums, int index, int remain)
    {
        if (remain == 0)
        {
            res.push_back(nums);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates.at(i) > remain)
                break;
            nums.push_back(candidates.at(i));
            findRes(candidates, nums, i, remain-candidates.at(i));
            nums.pop_back();
        }
    }

};

int main(int argc, char const *argv[])
{
    vector<int> vec = {7,3,2};
    int target = 18;
    Solution sol;
    PrintUtils::printf(sol.combinationSum(vec, target));
    getchar();
    return 0;
}