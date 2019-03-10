#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() < 1)
            return 0;
        int length = 0;
        int end = s.length()-1;
        while (s[end] == ' ')
            end--;
        for (int i = end; i >= 0; i--)
        {
            if (s[i] == ' ')
                break;
            length++;
        }
        return length;
    }
};