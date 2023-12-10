//
// Created by sc on 2023/9/18.
//
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    static bool cmp(int a, int b)
    {
        return std::abs(a) > abs(b);
    }
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), cmp);

        for(auto& elem : nums)
        {
            if(elem < 0 && k > 0)
            {
                elem *= -1;
                --k;
            }
        }
        if( k % 2 == 1) nums.back() *= -1;

        int res = 0;
        for(const auto& elem : nums)
            res += elem;
        return res;
    }
};