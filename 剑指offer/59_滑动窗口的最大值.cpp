//
// Created by sc on 2023/4/23.
//


#include <vector>
#include <queue>
using std::deque;
using std::vector;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> cache;
        for (int i = 0; i < k; ++i)
        {
            while (!cache.empty() && nums[i] >= nums[cache.back()]) cache.pop_back();
            cache.push_back(i);
        }

        res.push_back(nums[cache.front()]);

        for (int i = k; i < nums.size(); ++i) {
            while (!cache.empty() && nums[i] >= nums[cache.back()]) cache.pop_back();
            cache.push_back(i);

            while (!cache.empty() && cache.front() < i-k+1) cache.pop_front();

            res.push_back(nums[cache.front()]);
        }

        return res;
    }
};