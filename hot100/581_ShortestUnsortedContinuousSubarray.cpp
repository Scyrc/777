//
// Created by sc on 2023/4/2.
//
#include <vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int maxV = nums[0];
        int minV= nums[len-1];
        int l = -1, r= -1;
        for (int i = 0; i < len; ++i) {
            if(nums[i] < maxV) r = i;
            else maxV = nums[i];

            if(nums[len - 1 - i] > minV) l = len - 1 -i;
            else minV = nums[len - 1 - i];
        }
        return r == -1 ? 0: r - l + 1;
    }
};