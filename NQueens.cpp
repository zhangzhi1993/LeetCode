#include <vector>
#include <string>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> resVecs;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            findQueens(resVecs, res, i, n);
        }
        PrintUtils::printf(resVecs);
        // PrintUtils::printf(1);
        vector<vector<string>> resStrs;
        string points;
        for (int j = 0; j < n; j++)
        {
            points.push_back('.');
        }
        points.push_back('\0');
        // for (int i = 0; i < resVecs.size(); i++)
        // {
        //     vector<int> locs = resVecs.at(i);
        //     vector<string> strs;
        //     for (int j = 0; j < n; j++)
        //     {
        //         string a = points;
        //         a[locs.at(j)] = 'Q';
        //         strs.push_back(a);
        //     }
        //     resStrs.push_back(strs);
        // }
        return resStrs;
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
    PrintUtils::printf(sol.solveNQueens(n));
    getchar();
    return 0;
}