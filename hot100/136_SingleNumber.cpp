//
// Created by sc on 2023/3/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int& x :  nums)
        {
            ans ^= x;
        }
        return ans;
    }
};