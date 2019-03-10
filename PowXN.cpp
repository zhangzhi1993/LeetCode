#include <vector>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;
        if (n < 0 && n > -10)
            return 1/innerPow(x, -n);
        else if (n <= -1)
            return 1/innerPow(x, -(n+1))/x; //防止-2147483648不能直接转换成2147483648
        else if (n > 0)
            return innerPow(x, n);
        else
            return 1;    
    }

    double innerPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double res = x;
        unsigned i = 2; //i*=2可能大于2147483647
        for (; i <= n; i*=2)
        {
            res *= res;
        }
        if (i > n)
        {
            res *= innerPow(x, n - i/2);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    PrintUtils::printf(sol.myPow(0.00001,2147483647));
    getchar();
    return 0;
}