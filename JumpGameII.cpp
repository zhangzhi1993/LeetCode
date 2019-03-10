#include <vector>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        vector<int> res(nums.size(), 0x7fffffff);
        res[0] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((i-j) <= nums.at(j))
                {
                    res[i] = res.at(i) > (res.at(j) + 1) ? 
                        (res.at(j) + 1) : res.at(i);
                }
            }
        }
        PrintUtils::printf(res);
        return res.at(nums.size()-1);
    }

    int jump(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int level = 0, curMax = 0, nextMax = 0, i = 0;
        while (curMax-i+1 > 0)
        {
            level++;
            for(; i<=curMax; i++)
            {
                nextMax = nextMax > (nums.at(i)+i) ? nextMax : (nums.at(i)+i);
                if (nextMax >= nums.size()+1)
                    return level;
            }
            curMax = nextMax;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {2,3,1,1,4};
    Solution sol;
    PrintUtils::printf(sol.jump(vec));
    getchar();
    return 0;
}