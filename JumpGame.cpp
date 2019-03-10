#include <vector>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 1)
            return true;
        vector<bool> res(nums.size(), false);
        res[nums.size()-1] = true;
        for (int i = nums.size()-2; i >= 0; i--)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if (res.at(j) == true && nums.at(i) >= (j-i))
                {
                    res[i] = true;
                    break;
                }
            }
        }
        // PrintUtils::printf(res);
        return res.at(0);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {2,3,1,1,4};
    Solution sol;
    PrintUtils::printf(sol.canJump(vec));
    getchar();
    return 0;
}