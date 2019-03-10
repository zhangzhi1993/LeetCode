#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> strsMap;
        for (string s : strs)
        {
            string k = s;
            sort(k.begin(), k.end());
            strsMap[k].push_back(s);
        }
        vector<vector<string>> res;
        for (auto k : strsMap)
        {
            res.push_back(k.second);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> vec = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    PrintUtils::printf(sol.groupAnagrams(vec));
    getchar();
    return 0;
}