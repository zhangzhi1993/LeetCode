/*
推荐办法：直接通过三种情况的二维数组的赋值确定有效性，即每个9数字是否重复
*/
// bool isValidSudoku(vector<vector<char> > &board)
// {
//     int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    
//     for(int i = 0; i < board.size(); ++ i)
//         for(int j = 0; j < board[i].size(); ++ j)
//             if(board[i][j] != '.')
//             {
//                 int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
//                 if(used1[i][num] || used2[j][num] || used3[k][num])
//                     return false;
//                 used1[i][num] = used2[j][num] = used3[k][num] = 1;
//             }
    
//     return true;
// }


#include <iostream>
#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> trans = board;
        vector<vector<char>> subs = board;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                trans[i][j] = board[j][i];
                subs[i][j] = board[i/3*3+j/3][i%3*3+j%3];
                // cout << "(" << i/3*3+j/3 << "," << i%3*3+j%3 << ")" << endl;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            if (!check9Nums(board.at(i)))
                return false;
            if (!check9Nums(trans.at(i)))
                return false;
            if (!check9Nums(subs.at(i)))
                return false;
        }
        return true;
    }

    bool check9Nums(vector<char> &nums)
    {
        set<char> abc;
        for (int i = 0 ; i < nums.size(); i++)
        {
            if (abc.find(nums.at(i)) != abc.end() && nums.at(i) != '.')
                return false;
            else
            {
                abc.insert(nums.at(i));
            }
        }
        return true;
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
    PrintUtils::printf(sol.isValidSudoku(vec));
    PrintUtils::printf(vec);
    getchar();
    return 0;
}

