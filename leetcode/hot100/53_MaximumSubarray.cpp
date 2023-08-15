//
// Created by sc on 2023/3/6.
//
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxVal = nums[0];
        int curSum = nums[0];
        for(int i =1;i<nums.size();++i)
        {
            if(curSum >= 0)
            {
                curSum += nums[i];
                maxVal = std::max(maxVal, curSum);
            }
            else
            {
                curSum = nums[i];
                maxVal = std::max(maxVal, curSum);
            }
        }
        return maxVal;
    }
};