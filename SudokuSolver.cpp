/*
和八皇后的思想类似，属于广度优先搜索的一种
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    bool cols[9][9] = {};
    bool rows[9][9] = {};
    bool subs[9][9] = {};
    bool found = false;

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board.at(i).at(j) != '.')
                {
                    rows[i][board.at(i).at(j)-'1'] = true;
                    cols[j][board.at(i).at(j)-'1'] = true;
                    subs[i/3*3+j/3][board.at(i).at(j)-'1'] = true;
                }
            }
        }
        find(0, board);
    }

    void find(int n, vector<vector<char>>& board)
    {
        if (n == 81)
        {
            found = true;
            return;
        }
        int i = n / 9;
        int j = n % 9;
        int index = i/3*3+j/3;
        if (board.at(i).at(j) == '.')
        {
            for (int k = 0; k < 9; k++)
            {
                //同一二维位置在三种情况下都可以赋予某值才继续进行
                if (!rows[i][k] && !cols[j][k] && !subs[index][k])
                {
                    rows[i][k] = true;
                    cols[j][k] = true;
                    subs[index][k] = true;
                    board[i][j] = k + '1';

                    find(n+1, board);
                    if (found)
                        return;

                    rows[i][k] = false;
                    cols[j][k] = false;
                    subs[index][k] = false;
                    board[i][j] = '.';
                }
            }
        }
        else
        {
            find(n+1, board);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<char> vec1 = {'5','3','.','.','7','.','.','.','.'};
    vector<char> vec2 = {'6','.','.','1','9','5','.','.','.'};
    vector<char> vec3 = {'.','9','8','.','.','.','.','6','.'};
    vector<char> vec4 = {'8','.','.','.','6','.','.','.','3'};
    vector<char> vec5 = {'4','.','.','8','.','3','.','.','1'};
    vector<char> vec6 = {'7','.','.','.','2','.','.','.','6'};
    vector<char> vec7 = {'.','6','.','.','.','.','2','8','.'};
    vector<char> vec8 = {'.','.','.','4','1','9','.','.','5'};
    vector<char> vec9 = {'.','.','.','.','8','.','.','7','9'};
    vector<vector<char>> vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);
    vec.push_back(vec5);
    vec.push_back(vec6);
    vec.push_back(vec7);
    vec.push_back(vec8);
    vec.push_back(vec9);
    Solution sol;
    sol.solveSudoku(vec);
    PrintUtils::printf(vec);
    getchar();
    return 0;
}