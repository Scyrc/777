//
// Created by sc on 2023/3/26.
//


#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int maxSide = 0;
        int maxLimit = min(row, col);
        vector<vector<int>> dp(row + 1, vector<int>(col+1, 0));

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i+1][j+1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1;
                    maxSide = max(maxSide, dp[i+1][j+1]);
                    if(maxSide == maxLimit) return maxSide*maxSide;
                }
            }
            
        }

        return maxSide*maxSide;
    }
};