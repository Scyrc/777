//
// Created by sc on 2023/8/23.
//
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;

        sort(nums.begin(), nums.end());

        for (int k = 0; k < nums.size() - 3; ++k)
        {
            if(nums[k] > target && nums[k] >= 0) break;
            if(k > 0 && nums[k] == nums[k-1]) continue;

            for (int i = k+1; i < nums.size() - 2; ++i)
            {
                if(nums[i] + nums[k] > target && nums[k] >= 0) break;
                if(i > k+1 && nums[i] == nums[i-1]) continue;
                int left = i + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    long sum = (long)nums[k] + nums[i] + nums[left] + nums[right];
                    if(sum == target)
                    {
                        res.push_back({nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) ++left;
                        while (left < right && nums[right] == nums[right-1]) --right;
                        ++left;
                        --right;
                    }
                    else if(sum < target)
                    {
                        ++left;
                    }
                    else
                    {
                        --right;
                    }
                }
            }
        }


        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {1,-2,-5,-4,-3,3,3,5};
    auto x = s.fourSum(vec, -11);
    return 0;
}