#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "PrintUtils.cpp"
using namespace std;
/*
    LeetCode提供了三种解法，极富有参考意义，分别是
    （1）动态规划
    （2）栈
    （3）从左向右扫描，再从右向左扫描
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int nMax = 0;
        if (s.length() < 2)
            return 0;
        int dp[s.length()] = {0};
        for (int i = 1; i < s.length(); i++)
        {
            if (s.at(i) == ')')
            {
                if (s.at(i-1) == '(')
                {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                }
                else if((i > dp[i-1]) && (s.at(i-dp[i-1]-1) == '('))
                {
                    dp[i] = dp[i-1] + ((i-dp[i-1]) >= 2 ? dp[i-dp[i-1]-2] : 0) + 2;
                }
            }
            nMax = nMax > dp[i] ? nMax : dp[i];          
        }
        return nMax;
    }
};

int main(int argc, char const *argv[])
{
    string s = "(())()((()))";
    Solution sol;
    PrintUtils::printf(sol.longestValidParentheses(s));
    getchar();
    return 0;
}