//
// Created by sc on 2023/9/18.
//
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0;
        for (int i = 0; i < prices.size()-1; ++i)
        {
            if(prices[i+1] > prices[i])
                res += (prices[i+1] - prices[i]);
        }

        return res;
    }
};