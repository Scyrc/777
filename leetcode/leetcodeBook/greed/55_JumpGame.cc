//
// Created by sc on 2023/9/18.
//
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if(nums.size() == 1) return 0;
        int currIndex = 0,maxIndex = 0;
        while (currIndex <= maxIndex)
        {
            int tmp = currIndex + nums[currIndex];
            maxIndex = maxIndex < tmp ? tmp : maxIndex;
            if(maxIndex >= nums.size() - 1) return true;
            ++currIndex;
        }

        return false;
    }
};