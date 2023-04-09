//
// Created by sc on 2023/4/9.
//

#include <vector>

using std::vector;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> cacheV (len, 0);
        for(int& x : nums)
        {
            if(++cacheV[x] == 2) return x;
        }
        return -1;
    }
};