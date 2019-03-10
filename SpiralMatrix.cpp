#include <vector>
#include <string>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() < 1)
            return res;
        if (matrix.size() < 2)
        {
            return matrix.at(0);
        }
        for (int col = 0 ; col < min(matrix.size()+1,matrix.at(0).size()+1)/2; col+=1)
        {
            spiral(matrix, res, col, col, matrix.size(), matrix.at(0).size());
        }
        return res;
    }

    void spiral(vector<vector<int>>& matrix, vector<int> &res, int col, int row, int height, int width)
    {
        if (row < height)
            for (int i = col; i < width-col; i++)
                res.push_back(matrix.at(row).at(i));
        if (width-col-1 >= 0)
            for (int i = row+1; i < height-row; i++)
                res.push_back(matrix.at(i).at(width-col-1));
        if (height-row-1 > row)
            for (int i = width-col-2; i >= col; i--)
                res.push_back(matrix.at(height-row-1).at(i));
        if (col < width-col-1)
            for (int i = height-row-2; i > row; i--)
                res.push_back(matrix.at(i).at(col));
    }
};

