//
// Created by sc on 2023/4/16.
//


#include <vector>
using std::vector;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int count =1;
        int selectItem = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == selectItem) ++count;
            else if(--count == 0)
            {
                selectItem = nums[i];
                count = 1;
            }
        }

        return selectItem;
    }
};