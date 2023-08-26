//
// Created by sc on 2023/8/26.
//
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cacheMap;
        int maxCount = 0;
        for(auto& elem : nums)
        {
            maxCount = maxCount < ++cacheMap[elem] ? cacheMap[elem] : maxCount;
        }

        vector<vector<int>> buckets (maxCount + 1);
        for(auto& pair : cacheMap)
        {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for (int i = maxCount; i > 0 &&  res.size() <k; --i)
        {
            for(auto& v : buckets[i])
            {
                res.push_back(v);
            }
        }

        return res;
    }
};