//
// Created by sc on 2023/4/2.
//
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        int allSum = 0;
        for(auto& x : nums) allSum += x;
        if((allSum + target) % 2 == 1 || abs(target)>allSum) return 0;

        target = (allSum + target) / 2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(auto& x : nums)
        {
            for (int i = target; i > x-1; --i) {
                dp[i] += dp[i-x];
            }
        }
        return dp[target];
    }
};