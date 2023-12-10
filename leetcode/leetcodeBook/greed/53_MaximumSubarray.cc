//
// Created by sc on 2023/9/18.
//
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = numeric_limits<int>::min();
        int currSum = 0;
        for(const auto& elem : nums)
        {
            if(currSum <= 0)
            {
                currSum = elem;
            }
            else
            {
                currSum += elem;
            }
            res = res < currSum ? currSum : res;
        }
        return res;
    }
};