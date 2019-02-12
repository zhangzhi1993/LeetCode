#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int nLongest = 0;
        set<char> sLongest;
        if (s.length() <= 1)
        {
            nLongest = s.length();
        }
        else
        {
            int i = 0;
            sLongest.insert(s.at(0));
            for (int j = 1; j < s.length(); )
            {
                char c = s.at(j);
                if (sLongest.find(c) != sLongest.end())
                {
                    sLongest.erase(s.at(i));
                    i++;
                }
                else
                {
                    j++;
                    sLongest.insert(c);
                    nLongest = (j-i) > nLongest ? (j-i) : nLongest;
                }
                
            }
        }
        return nLongest;
    }
};

int main(int argc, char const *argv[])
{
    // string abc = "abcabcbb";
    // string abc = "abcabcdbb";
    // string abc = "bbbbb";
    // string abc = "pwwkew";
    string abc = "";
    Solution s;
    std::cout << s.lengthOfLongestSubstring(abc) << std::endl;
    getchar();
    return 0;
}