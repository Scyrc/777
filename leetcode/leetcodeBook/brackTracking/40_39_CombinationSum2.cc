//
// Created by sc on 2023/9/6.
//
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
    void backTracking(const int& startIndex, vector<int>& select, const vector<int>& candidates,int& target)
    {
        if(target == 0)
        {
            res.push_back(select);
        }
        set<int> cache;
        for (int i = startIndex; i < candidates.size(); ++i)
        {
            if(candidates[i] > target )
                break;
            if(cache.count(candidates[i]) > 0)
                continue;
            cache.insert(candidates[i]);
            target -= candidates[i];
            select.push_back(candidates[i]);
            backTracking(i + 1, select, candidates, target);
            select.pop_back();
            target += candidates[i];
        }
    }
public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> select;
        sort(candidates.begin(), candidates.end());
        backTracking(0, select, candidates, target);
        return res;
    }
};