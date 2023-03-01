//
// Created by sc on 2023/3/1.
//

#include "vector"
#include <iostream>

using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void reverse(vector<int>& nums, int i, int j){
        while (i < j)
        {
            swap(nums, i ,j);
            ++i;
            --j;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int k= -1;
        int l= -1;
        for(int i=len-2;i>=0;--i)
        {
            if(nums[i]<nums[i+1])
            {
                k = i;
                break;
            }
        }
        if(k==-1)
        {
            reverse(nums, 0, len - 1);
            return;
        }
        for(int i=len-1;i>=0;--i)
        {
            if(nums[k]<nums[i])
            {
                l = i;
                break;
            }
        }
        swap(nums, k ,l);
        reverse(nums, k+1, len - 1);
    }
};