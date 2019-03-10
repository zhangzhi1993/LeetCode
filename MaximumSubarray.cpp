#include <vector>
#include <string>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> res;
        if (nums.size() < 1)
            return 0;
        if (nums.size() < 2)
            return nums.at(1);
        res.push_back(nums.at(0));
        int max = nums.at(0);
        for (int i = 1; i < nums.size(); i++)
        {
            if (res.at(i-1) < 0)
                res.push_back(nums.at(i));
            else
            {
                res.push_back(nums.at(i)+res.at(i-1));
            }
            max = res.at(i) > max ? res.at(i) : max;
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    PrintUtils::printf(sol.maxSubArray(nums));
    getchar();
    return 0;
}