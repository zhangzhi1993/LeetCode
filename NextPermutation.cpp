#include <iostream>
#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return;
        }
        if (nums.size() == 2)
        {
            swap(nums.at(0), nums.at(1));
            return;
        }
        int i = nums.size() - 2;
        while (i >= 0 && (nums.at(i+1) <= nums.at(i)))
        {
            i--;
        }
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && (nums.at(j) <= nums.at(i)))
            {
                j--;
            }
            swap(nums.at(i), nums.at(j));
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {1, 2, 3};
    Solution sol;
    for (int i = 0; i < 10; i++)
    {
        PrintUtils::printf(vec);
        sol.nextPermutation(vec);
    }
    getchar();
    return 0;
}