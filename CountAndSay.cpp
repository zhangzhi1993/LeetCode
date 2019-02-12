#include <iostream>
#include <sstream>
#include "PrintUtils.cpp"

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 2; i <= n; i++)
        {
            str = nextSay(str);
        }
        return str;
    }

    string nextSay(string str)
    {
        string res;
        char preChar = str.at(0);
        int n = 1;
        for (int i = 1; i < str.size(); i++)
        {
            if (str.at(i) == preChar)
            {
                n++;
            }
            else 
            {
                ostringstream stream;
                stream << n;
                res += stream.str();
                res += preChar;
                n = 1;
                preChar = str.at(i);
            }
        }
        ostringstream stream;
        stream << n;
        res += stream.str();
        res += preChar;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int i = 1;
    Solution sol;
    PrintUtils::printf(sol.countAndSay(i));
    getchar();
    return 0;
}