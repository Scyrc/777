//
// Created by sc on 2023/4/23.
//
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int minV = prices[0];
        int res = 0;

        for (int i = 1; i < prices.size(); ++i) {
            if(prices[i] <= minV) minV = prices[i];
            else res = std::max(res, prices[i] - minV);
        }
        return res;
    }
};
