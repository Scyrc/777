//
// Created by sc on 2023/9/18.
//
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums)
    {
        if(nums.size() == 1) return 0;

        int currIndex = 0,maxIndex = 0;
        int step = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxIndex = max(maxIndex, i + nums[i]);

            if(i == currIndex)
            {
                ++step;
                currIndex = maxIndex;
                if(maxIndex >= nums.size() - 1) return step;
            }
        }

        return step;
    }
};