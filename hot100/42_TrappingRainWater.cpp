//
// Created by sc on 2023/3/4.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> leftMax(len,0);
        vector<int> rightMax(len,0);
        for(int i =1;i<len;++i)
        {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }
        for(int i =len-2; i>=0;--i)
        {
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }
        int water = 0;
        for(int i=0;i<len;i++)
        {
            int val = min(leftMax[i], rightMax[i]) - height[i];
            water += max(0, val);
        }
        return water;
    }
};