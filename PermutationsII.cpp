#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        innerPermutation(nums, 0);
        return res;
    }

    void innerPermutation(vector<int> nums, int k) {
        //和普通的全排列不同，不能交换回来。这样才能保证[k]的不会被重复
        if (k >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = k; i < nums.size(); i++)
        {
            if (i == k || nums[i] != nums[k])
            {
                swap(nums[k], nums[i]);
                innerPermutation(nums, k+1); 
            } 
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {1,1,2,2};
    Solution sol;
    PrintUtils::printf(sol.permuteUnique(vec));
    getchar();
    return 0;
}