//
// Created by sc on 2023/4/23.
//
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vector<int> cache;
        for(auto x : nums)
        {
            if(x!=0) cache.push_back(x);
        }

        int zeroCount = nums.size() - cache.size();

        if(zeroCount>=4) return true;

        std::sort(cache.begin(), cache.end());

        int diff =0;
        for (int i = 1; i < cache.size(); ++i) {
            if((cache[i] - cache[i-1]) == 0) return false;
            diff += (cache[i] - cache[i-1] -1);
            if(diff > zeroCount) return false;
        }
        return true;
    }
};