//
// Created by sc on 2023/4/17.
//

#include <vector>
using std::vector;
class Solution {
public:
    int maxValue(vector<vector<int>>& dp) {
        if(dp.size() == 0 || dp[0].size() == 0) return 0;
        int row = dp.size(), col = dp[0].size();
        for (int i = 1; i < row; ++i) {
            dp[i][0] += dp[i-1][0];
        }
        for (int j = 1; j < col; ++j) {
            dp[0][j] += dp[0][j-1];
        }

        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                dp[i][j] += std::max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[row-1][col-1];
    }
};