//
// Created by sc on 2023/4/9.
//
#include <vector>
using std::vector;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 ||  matrix[0].size() == 0) return false;
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0;
        while (i>=0 && j<col)
        {
            if(matrix[i][j] > target) --i;
            else if(matrix[i][j] < target) ++j;
            else return true;
        }
        return false;
    }
};