//
// Created by sc on 2023/4/16.
//

#include <vector>
using std::vector;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int cache = nums[0];
        int maxV = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if(cache>0) cache+=nums[i];
            else cache = nums[i];
            maxV = std::max(maxV, cache);
        }
        return maxV;
    }
};