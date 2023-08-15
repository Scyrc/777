//
// Created by sc on 2023/3/8.
//
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;

        for(int i=0;i<nums.size();i++)
        {
            int tmp = nums[i];
            nums[i] = 2;
            if(tmp < 2) { nums[p1++] = 1;}
            if(tmp < 1) { nums[p0++] = 0;}
        }
    }
};