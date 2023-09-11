//
// Created by sc on 2023/9/11.
//
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

public:
    void backTracking(const int& startIndex, const vector<int>& nums)
    {
        res.push_back(path);
        if(startIndex >= nums.size()) return;
        unordered_set<int> cacheSet;
        for (int i = startIndex; i < nums.size(); ++i)
        {
            if(cacheSet.count(nums[i]) > 0) continue;
            cacheSet.insert(nums[i]);
            path.push_back(nums[i]);
            backTracking(i + 1, nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        backTracking(0, nums);
        return res;
    }
};