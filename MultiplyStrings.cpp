#include <string>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> mid(num1.length() + num2.length(), 0);
        for (int i = num1.length() - 1; i >= 0; i--)
        {
            int a = num1.at(i) - '0';
            for (int j = num2.length() - 1; j >= 0; j--)
            {
                int temp = a * (num2.at(j) - '0');
                int pos1 = i + j + 1;
                int pos2 = i + j;
                int sum = temp + mid.at(pos1);
                mid[pos1] = sum % 10;
                mid[pos2] += sum / 10; //解决了进位再进位的问题，这也是用vector<int>中转而不是直接用string的原因，否则需要麻烦地递归进位
            }
        }
        string res;
        for (int i = 0; i < mid.size(); i++)
        {
            if (!(res.length() == 0 && mid.at(i) == 0))
            {
                res += ('0' + mid.at(i));
            }
        }
        return res.size() ? res : "0";
    }
};

int main(int argc, char const *argv[])
{
    string a = "123";
    string b = "456";
    Solution sol;
    PrintUtils::printf(sol.multiply(a, b));
    getchar();
    return 0;
}