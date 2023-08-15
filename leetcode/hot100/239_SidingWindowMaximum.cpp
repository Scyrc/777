//
// Created by sc on 2023/3/28.
//

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> q;
        for(int i=0; i< k;++i)
        {
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }

        vector<int> res(1, nums[q.front()]);

        for(int i =k; i<nums.size();++i)
        {
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);

            while (q.front() <= i-k) q.pop_front();

            res.push_back(nums[q.front()]);
        }
        return res;
    }
};