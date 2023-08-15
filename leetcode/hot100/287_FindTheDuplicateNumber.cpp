//
// Created by sc on 2023/3/29.
//
#include<vector>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow) break;
        }
        int start = 0;
        while (true)
        {
            start = nums[start];
            slow = nums[slow];
            if(slow == start) break;
        }

        return slow;
    }
};