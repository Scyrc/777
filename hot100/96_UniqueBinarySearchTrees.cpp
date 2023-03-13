//
// Created by sc on 2023/3/13.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i< n+1;++i)
        {
            for(int j = 1;j<i+1;++j)
            {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};