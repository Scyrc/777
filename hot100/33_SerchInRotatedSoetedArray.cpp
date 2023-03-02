//
// Created by sc on 2023/3/2.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r = nums.size()-1;
        while (l <=r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] == target) return mid;
            if(nums[l] <= nums[mid] )
            {
                if(nums[l]<=target && target<nums[mid]) // [0,mid]无反转，且target在范围内，向左
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if(target > nums[mid] && target <= nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid -1 ;
            }
        }
        return -1;
    }
};