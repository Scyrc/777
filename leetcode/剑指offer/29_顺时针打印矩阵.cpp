//
// Created by sc on 2023/4/13.
//
//
// Created by sc on 2023/4/13.
//
#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0 || matrix[0].size() == 0) return res;
        int row = matrix.size(), col = matrix[0].size();
        int direction = 1;
        int i = 0, j = 0;
        res.push_back(matrix[0][0]);
        while (res.size() < row*col)
        {
            matrix[i][j] = INT_MAX;
            switch (direction) {
                case 1:
                    if(j<col - 1 && matrix[i][j + 1] != INT_MAX)
                    {
                        res.push_back(matrix[i][++j]);
                        continue;
                    }
                    else
                    {
                        direction = 2;
                    }
                case 2:
                    if(i<row - 1 && matrix[i+1][j] != INT_MAX)
                    {
                        res.push_back(matrix[++i][j]);
                        continue;
                    }
                    else
                    {
                        direction = 3;
                    }
                case 3:
                    if(j>0 && matrix[i][j-1] != INT_MAX)
                    {
                        res.push_back(matrix[i][--j]);
                        continue;
                    }
                    else
                    {
                        direction = 4;
                    }
                case 4:
                    if(i>0 && matrix[i-1][j] != INT_MAX)
                    {
                        res.push_back(matrix[--i][j]);
                        continue;
                    }
                    else
                    {
                        direction = 1;
                    }
            }
        }
        return res;
    }
};

