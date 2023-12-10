//
// Created by sc on 2023/9/19.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[0] < b[0];
        });

        int res = 1;
        int currMaxBound = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if(currMaxBound >= points[i][0])
            {
                currMaxBound = min(currMaxBound, points[i][1]);
            }
            else
            {
                currMaxBound = points[i][1];
                ++res;
            }
        }

        return res;
    }
};