#include <vector>
#include <algorithm>
#include "PrintUtils.cpp"
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size()/2; i++)
        {
            innerRotate(matrix, i);
        }
    }
    void innerRotate(vector<vector<int>>& matrix, int ring)
    {
        int point = matrix.size() - ring - 1;
        for (int i = ring; i < point; i++)
        {
            int temp = matrix.at(ring).at(i);
            matrix[ring][i] = matrix[matrix.size()-1-i][ring];
            matrix[matrix.size()-1-i][ring] = matrix[matrix.size()-1-ring][matrix.size()-1-i];
            matrix[matrix.size()-1-ring][matrix.size()-1-i] = matrix[i][matrix.size()-1-ring];
            matrix[i][matrix.size()-1-ring] = temp;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec1 = {5,1,9,11};
    vector<int> vec2 = {2, 4, 8,10};
    vector<int> vec3 = {13, 3, 6, 7};
    vector<int> vec4 = {15,14,12,16};
    
    vector<vector<int>> vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);
    Solution sol;
    sol.rotate(vec);
    PrintUtils::printf(vec);
    getchar();
    return 0;
}