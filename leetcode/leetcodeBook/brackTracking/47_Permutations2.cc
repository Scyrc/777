//
// Created by sc on 2023/9/14.
//
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> select;

    void backTracking(vector<int>& nums, const int& targetLength)
    {
        if(select.size() == targetLength)
        {
            res.push_back(select);
        }
        if(nums.empty()) return;

        unordered_set<int> cacheSet;
        for (int i = 0; i < nums.size(); ++i)
        {
            if(cacheSet.count(nums[i]) > 0) continue;
            cacheSet.insert(nums[i]);
            const int tmp = nums[i];
            select.push_back(tmp);
            nums[i] = nums.back();
            nums.pop_back();
            backTracking(nums, targetLength);
            select.pop_back();
            nums.push_back(nums[i]);
            nums[i] = tmp;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backTracking(nums, nums.size());
        return res;
    }
};

int main()
{
    vector<int> nums {1, 1, 2};
    Solution s;
    s.permuteUnique(nums);
}