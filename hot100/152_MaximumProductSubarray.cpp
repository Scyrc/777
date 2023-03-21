//
// Created by sc on 2023/3/21.
//

#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;

        int dpMax = nums[0];
        int dpMin = nums[0];
        int Max = nums[0];
        for(int i = 1; i< len; ++i)
        {
            int preMax = dpMax;
            dpMax = max(dpMax * nums[i], max(dpMin * nums[i], nums[i]));
            dpMin = min(preMax * nums[i], min(dpMin * nums[i], nums[i]));
            Max  = max(Max, dpMax);
        }
        return Max;
    }
};