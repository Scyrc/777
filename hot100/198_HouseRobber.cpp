//
// Created by sc on 2023/3/23.
//
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        if(len == 2) return max(nums[0], nums[1]);

        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int res = max(nums[0], nums[1]);
        for(int i = 2; i< len; ++i)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};
