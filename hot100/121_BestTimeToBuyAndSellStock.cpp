//
// Created by sc on 2023/3/16.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int res = 0;
        for(int i =0;i<prices.size();++i)
        {
            if(prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else
            {
                res = prices[i] - minPrice > res ? prices[i] - minPrice : res;
            }
        }
        return res;
    }
};