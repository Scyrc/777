//
// Created by sc on 2023/3/6.
//
#include <vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxVal = 0;
        int i =0;
        while (i<=maxVal)
        {
            maxVal = std::max(maxVal, i+nums[i]);
            if(maxVal >= nums.size()-1) return true;
            i++;
        }

        return false;
    }
};