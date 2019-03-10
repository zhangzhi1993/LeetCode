#include <vector>
#include <string>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix0;
        int res = 1;
        if (n < 1)
            return matrix0;
        if (n < 2)
        {
            vector<int> row = {res};
            matrix0.push_back(row);
            return matrix0;
        }
        vector<int> row(n, 1);
        vector<vector<int>> matrix(n, row);
        for (int col = 0 ; col < (n+1)/2; col++)
        {
            spiral(matrix, res, col, col, n, n);
        }
        return matrix;
    }

    void spiral(vector<vector<int>>& matrix, int &res, int col, int row, int height, int width)
    {
        if (row < height)
            for (int i = col; i < width-col; i++)
                matrix[row][i] = res++;
        if (width-col-1 >= 0)
            for (int i = row+1; i < height-row; i++)
                matrix[i][width-col-1] = res++;
        if (height-row-1 > row)
            for (int i = width-col-2; i >= col; i--)
                matrix[height-row-1][i] = res++;
        if (col < width-col-1)
            for (int i = height-row-2; i > row; i--)
                matrix[i][col] = res++;
    }
};

int main(int argc, char const *argv[])
{
    int target = 4;
    Solution sol;
    PrintUtils::printf(sol.generateMatrix(target));
    getchar();
    return 0;
}