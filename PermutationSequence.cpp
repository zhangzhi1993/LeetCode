#include <vector>
#include <string>
#include <algorithm>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            nums.push_back(i+1);
        }
        for (int i = 1; i < k; i++)
        {
            nextPermutation(nums);
        }
        string s;
        for (int i = 0; i < n; i++)
        {
            s += ('0' + nums.at(i));
        }
        s += '\0';
        return s;
    }

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
    int n = 3;
    int k = 4;
    Solution sol;
    PrintUtils::printf(sol.getPermutation(n, k));
    getchar();
    return 0;
}