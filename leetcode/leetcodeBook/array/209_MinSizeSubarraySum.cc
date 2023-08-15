//
// Created by sc on 2023/8/15.
//

#include <vector>
#include <climits>
using namespace  std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int leftIndex = 0;
        int rightIndex = 1;
        int currentSum = nums[0];
        if(currentSum >= target) return 1;
        int minSize = INT_MAX;
        while (rightIndex < nums.size())
        {
            currentSum += nums[rightIndex++];

            if(currentSum >= target)
            {
                while (currentSum - nums[leftIndex] >= target)
                {
                    currentSum -= nums[leftIndex++];
                }

                minSize = rightIndex - leftIndex < minSize ? rightIndex - leftIndex : minSize;
                if(minSize == 1) return 1;
            }
        }
        return minSize == INT_MAX ? 0 : minSize;

    }
};

