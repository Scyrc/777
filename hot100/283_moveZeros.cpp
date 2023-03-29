//
// Created by sc on 2023/3/29.
//
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0) return;
        int j =0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0)
            {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
