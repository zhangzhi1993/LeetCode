#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        return innerMul(m, n); //直接用加法是过不了时间限制的，需要分割
    }

    int innerMul(int m, int n)
    {
        if (m < 4  || n  < 4)
            return innerSum(m, n, 1, 1);
        else
        {
            int res = 0;
            if (m < n)
            {
                for (int i = 1; i <= m; i++)
                {
                    res += innerMul(i, n/2)*innerMul(m-i+1, n-n/2);
                }
            }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    res += innerMul(m/2, i)*innerMul(m-m/2, n-i+1);
                }
            }
            return res;
        }
    }

    int innerSum(int m, int n, int right, int down)
    {
        if (m == right || n == down)
            return 1;
        else
        {
            return innerSum(m, n, right+1, down) + innerSum(m, n, right, down+1);
        }
    }
};

int main(int argc, char const *argv[])
{
    int m = 51;
    int n = 9;
    Solution sol;
    PrintUtils::printf(sol.uniquePaths(m, n));
    getchar();
    return 0;
}