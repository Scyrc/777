//
// Created by sc on 2023/3/4.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void help(vector<int>& candidates, vector<int> select, int target, int index)
    {
        if(target == 0)
        {
            res.push_back(select);
        }

        for(int i = index; i<candidates.size();i++)
        {
            if(candidates[i] <= target)
            {
                select.push_back(candidates[i]);
                help(candidates, select, target-candidates[i], i);
                select.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> select;
        help(candidates, select, target, 0);
        return res;
    }
};