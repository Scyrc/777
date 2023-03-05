//
// Created by sc on 2023/3/5.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> nums, vector<int> select)
    {
        if(nums.empty())
        {
            res.push_back(select);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            int tmp = nums[i];
            select.push_back(tmp);
            nums.erase(nums.begin() + i);
            dfs(nums, select);
            nums.insert(nums.begin() + i, tmp);
            select.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> select;
        dfs(nums, select);
        return res;
    }
};