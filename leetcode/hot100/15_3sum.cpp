//
// Created by sc on 2023/2/25.
//
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;

        std::sort(nums.begin(), nums.end());

        if(nums[0]>0 || nums[nums.size()-1] <0) return  res;

        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size() - 1;
            while (left<right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0)
                {
                    vector<int> oneRes = {nums[i], nums[left], nums[right]};
                    res.push_back(oneRes);
                    while (left<right && nums[left] == nums[left+1]) left++;
                    while (left<right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;

                }
                else if(sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return  res;
    }
};