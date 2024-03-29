//
// Created by sc on 2023/4/20.
//
#include <vector>
using std::vector;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() -1;
        while (l <=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return l;
    }
};