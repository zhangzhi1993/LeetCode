#include <vector>
#include <string>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> resVecs;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            findQueens(resVecs, res, i, n);
        }
        return resVecs.size();
    }

    void findQueens(vector<vector<int>> &resVecs, vector<int> res, int next, int size)
    {
        if (isNext(res, next))
        {
            res.push_back(next);
            if (res.size() == size)
            {
                resVecs.push_back(res);
                return;
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    findQueens(resVecs, res, i, size);
                }
            }
        }
    }

    bool isNext(vector<int>res, int next)
    {
        for (int i = 0; i < res.size(); i++)
        {
            if (res.at(i) == next || 
                (res.at(i)+res.size()-i) == next ||
                (res.at(i)-res.size()+i) == next)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    int n = 5;
    Solution sol;
    PrintUtils::printf(sol.totalNQueens(n));
    getchar();
    return 0;
}