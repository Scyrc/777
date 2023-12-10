//
// Created by sc on 2023/9/19.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });

        int res = 1;
        int currMaxBound = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if(currMaxBound > intervals[i][0])
            {
                currMaxBound = min(currMaxBound, intervals[i][1]);
            }
            else
            {
                currMaxBound = intervals[i][1];
                ++res;
            }
        }

        return intervals.size() -  res;
    }
};