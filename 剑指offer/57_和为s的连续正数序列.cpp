//
// Created by sc on 2023/4/22.
//

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if(target < 3) return  res;
        int l =1, r = 2;

        int sum = 3;

        while (r - l >=1)
        {
            if(sum == target)
            {
                vector<int> tmp(r-l+1);
                for (int i = l; i <=r; ++i)
                {
                    tmp[i - l] = i;
                }
                res.push_back(tmp);
                sum -= (l++);
            }
            else if(sum < target)
            {
                sum += (++r);
            }
            else // sum > target
            {
                sum -= (l++);
            }
        }

        return res;
    }
};