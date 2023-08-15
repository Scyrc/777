//
// Created by sc on 2023/3/12.
//
#include <vector>
#include <iostream>
using namespace std;
#include <iostream>
#include <vector>
#include <stack>
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sum (n+1, vector<int>(m, 0));

        for(int i=1;i<=n;++i)
        {
            for (int j = 0; j < m; ++j) {
                sum[i][j] = matrix[i-1][j] == '0' ? 0 : sum[i-1][j] + 1;
            }
        }

        int res = 0;
        for(int i=1;i<=n;++i)
        {
            res = max(res, largestRectangleArea(sum[i]));
        }
        return res;

    }

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
    vector<vector<char>> matrix;
    matrix.push_back(vector<char>(1, '1'));
    Solution s;
    cout<< s.maximalRectangle(matrix);
}