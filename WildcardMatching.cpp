#include <string>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    bool isMatch2(string s, string p) {
        if (p.length() == 0 && s.length() == 0)
            return true;
        if (p.length() == 0 && s.length() != 0)
            return false;
        if (p.length() != 0 && s.length() == 0)
        {
            for (int i = 0; i < p.length(); i++)
            {
                if (p.at(i) != '*')
                    return false;
            }
            return true;
        }
        vector<bool> matchs((p.length()+1)*(s.length()+1), false);
        // for (int i = 0; i <= p.length(); i++)
        // {
        //     matchs[i*(s.length()+1)] = true;
        // }
        // for (int j = 0; j <= s.length(); j++)
        // {
        //     matchs[j] = true;
        // }
        matchs[0] = true;
        for (int i = 1; i <= p.length(); i++)
        {
            char a = p.at(i-1);
            if (a == '*' && matchs.at((i-1)*(s.length()+1) + (0)) == true)
                matchs[i*(s.length()+1)] = true;
            for (int j = 1; j <= s.length(); j++)
            {
                if ((a == '*' && (matchs.at((i-1)*(s.length()+1) + (j-1)) == true || matchs.at((i)*(s.length()+1) + (j-1)) == true || matchs.at((i-1)*(s.length()+1) + (j)) == true))
                || ((a == '?' || a == s.at(j-1)) && matchs.at((i-1)*(s.length()+1) + (j-1)) == true))
                {
                    matchs.at((i)*(s.length()+1) + (j)) = true;
                }
            }
        }
        PrintUtils::printf(matchs);
        return matchs.at(matchs.size()-1);
    }

    bool isMatch(string s, string p) {
        int s0Pos = 0;
        int pPos = 0;
        int starPos = -1;
        int ssPos = 0;
        if (p.length() == 0 && s.length() == 0)
            return true;
        if (p.length() == 0 && s.length() != 0)
            return false;
        if (p.length() != 0 && s.length() == 0)
        {
            for (int i = 0; i < p.length(); i++)
            {
                if (p.at(i) != '*')
                    return false;
            }
            return true;
        }
        while(s0Pos < s.length())
        {
            if (pPos < p.length() && (p.at(pPos) == '?' || p.at(pPos) == s.at(s0Pos)))
            {
                pPos++;
                s0Pos++;
                continue;
            }
            if (pPos < p.length() && p.at(pPos) == '*')
            {
                starPos = pPos++;
                ssPos = s0Pos;
                continue;
            }
            if (starPos < p.length() && starPos >= 0) //不匹配情况下回退
            {
                pPos = starPos + 1;
                s0Pos = ++ssPos;
                continue;
            }
            return false;
        }

        for (; pPos < p.length(); pPos++)
        {
            if (p.at(pPos) != '*')
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string a = "aa";
    string b = "a";
    PrintUtils::printf(sol.isMatch(a, b));
    a = "aa";
    b = "*";
    PrintUtils::printf(sol.isMatch(a, b));
    a = "cb";
    b = "?a";
    PrintUtils::printf(sol.isMatch(a, b));
    a = "adceb";
    b = "*a*b";
    PrintUtils::printf(sol.isMatch(a, b));
    a = "acdcb";
    b = "a*c?b";
    PrintUtils::printf(sol.isMatch(a, b));
    a = "aab";
    b = "c*a*b";
    PrintUtils::printf(sol.isMatch(a, b));
    a = "a";
    b = "a*";
    PrintUtils::printf(sol.isMatch(a, b));
    getchar();
    return 0;
}