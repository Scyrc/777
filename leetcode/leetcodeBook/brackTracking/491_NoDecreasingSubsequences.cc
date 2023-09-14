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
    vector<int> maxElement;
    void backTracking(const int& startIndex, vector<int>& nums)
    {


        if(startIndex > nums.size() - 1)
        {
            return;
        }
        unordered_set<int> cacheSet;
        for (int i = startIndex; i < nums.size(); ++i) {
            if(nums[i] > maxElement[i]) continue;
            if(cacheSet.count(nums[i]) == 0 &&(select.empty() || select.back() <= nums[i]))
            {
                select.push_back(nums[i]);
                cacheSet.insert(nums[i]);
                if(select.size() > 1) res.push_back(select);
                backTracking(i + 1, nums);
                select.pop_back();

            }
        }
    }

    void calculate(vector<int>& nums)
    {
        int max = nums.back();
        maxElement.resize(nums.size());
        for (int i = nums.size()-1; i >-1 ; --i)
        {
            if(nums[i] > max)
                max = nums[i];

            maxElement[i] = max;
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        calculate(nums);
        backTracking(0, nums);
        return res;
    }
};