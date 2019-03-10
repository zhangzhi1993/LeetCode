#include <vector>
#include "PrintUtils.cpp"
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        innerPermutation(nums, 0);
        return res;
    }

    void innerPermutation(vector<int>& nums, int k) {
        if (k >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int i = k; i < nums.size(); i++)
        {
            swap(nums[k], nums[i]);
            innerPermutation(nums, k+1); //注意不是i+1，k+1才是全排列A(n,n);
            swap(nums[k], nums[i]);
        }
    }

};

int main(int argc, char const *argv[])
{
    vector<int> vec = {1,2,3};
    Solution sol;
    PrintUtils::printf(sol.permute(vec));
    getchar();
    return 0;
}