//
// Created by sc on 2023/8/23.
//
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> cacheSet;
        unordered_set<int> resSet;
        vector<int> res;
        for(auto& v : nums1)
        {
            cacheSet.insert(v);
        }
        for(auto& v : nums2)
        {
            if(cacheSet.contains(v) && !resSet.contains(v))
            {
                resSet.insert(v);
                res.push_back(v);
            }

        }

        return res;
    }
};