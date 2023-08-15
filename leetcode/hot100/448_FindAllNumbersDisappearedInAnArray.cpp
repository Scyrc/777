//
// Created by sc on 2023/3/31.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<bool> help(len, false);

        for(auto x : nums)
        {
            help[x-1] = true;
        }

        vector<int> res;

        for(int i=0;i<len;++i)
        {
            if(help[i] == false) res.push_back(i+1);
        }
        return res;
    }
};