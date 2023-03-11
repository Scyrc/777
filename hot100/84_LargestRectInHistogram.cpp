//
// Created by sc on 2023/3/11.
//

#include <vector>
#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int len = heights.size();
        if(len == 1) return heights[0];
        int res = heights[0];
        vector<int> cacheVector;
        for(int i=0;i<len;++i)
        {
            while (!cacheVector.empty() && heights[cacheVector.back()] > heights[i])
            {
                int height =  heights[cacheVector.back()];
                cacheVector.pop_back();
                int weight = i ;
                if (!cacheVector.empty())
                {
                    weight = i - cacheVector.back() -1;
                }
                res = max(res, height*weight);
            }
            cacheVector.push_back(i);
        }

        while (!cacheVector.empty())
        {
            int height =  heights[cacheVector.back()];
            cacheVector.pop_back();
            int weight = len;

            if (!cacheVector.empty())
            {
                weight = len - cacheVector.back() -1;
            }
            res = max(res, height*weight);

        }
        return res;
    }
};


int main()
{
    vector<int> heights{1,2,3,4,5};
    Solution s;
    cout<< s.largestRectangleArea(heights);
}