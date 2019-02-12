#include <vector>
#include <iostream>
#include "PrintUtils.cpp"
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            //不允许相连两次的分支添加同一个数字，但允许这次的这次主干的最后一个和将要的分支添加相同的数字
            if (i > index && candidates.at(i) == candidates.at(i-1))
                continue;
            nums.push_back(candidates.at(i));
            findRes(candidates, nums, i+1, remain-candidates.at(i));
            nums.pop_back();
        }
    }

};

int main(int argc, char const *argv[])
{
    vector<int> vec = {2,5,2,1,2};
    int target = 5;
    Solution sol;
    PrintUtils::printf(sol.combinationSum2(vec, target));
    getchar();
    return 0;
}