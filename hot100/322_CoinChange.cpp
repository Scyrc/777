//
// Created by sc on 2023/3/31.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(auto coin : coins)
        {
            for (int i = 0; i <= amount; ++i)
            {
                if(coin <= i) dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};