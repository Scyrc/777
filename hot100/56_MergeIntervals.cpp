//
// Created by sc on 2023/3/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        for(auto x : intervals)
        {
            if(x[0] <= end)
            {
                end = max(end, x[1]);
            }
            else
            {
                res.push_back(vector<int>{start, end});
                start = x[0];
                end = x[1];
            }
        }
        res.push_back(vector<int>{start, end});
        return res;
    }
};