//
// Created by sc on 2023/3/20.
//

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> cacheSet;
        for(auto& x : nums) cacheSet.insert(x);

        int res = 0;

        for(auto x : cacheSet)
        {
            if(cacheSet.count(x-1) == 0)
            {
                int y = x;
                while (cacheSet.count(y+1)>0) ++y;
                res = max(res, y - x + 1);
            }
        }

        return res;
    }
};