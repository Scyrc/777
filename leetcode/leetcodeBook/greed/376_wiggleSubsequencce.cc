//
// Created by sc on 2023/9/18.
//
#include <vector>
#include <array>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        vector<array<int, 2>> dp(nums.size());
        dp[0][0] = dp[0][1] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; ++j) {
                if(nums[j] > nums[i])
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);

                if(nums[j] < nums[i])
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }

        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};