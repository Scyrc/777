//
// Created by sc on 2023/4/5.
//
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        int maxCount = 0;
        for(auto& x : nums)
        {
            maxCount = std::max(maxCount, ++countMap[x]);
        }

        vector<vector<int>> buckets(maxCount + 1);
        for(const auto& pair : countMap)
        {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for (int i = maxCount; i>=0 && res.size() < k; --i) {
            for(const int& x : buckets[i])
            {
                res.push_back(x);
                if(res.size() == k) break;
            }

        }
        return res;
    }
};