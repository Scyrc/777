//
// Created by sc on 2023/2/25.
//


class Solution {
public:
    int maxArea(vector<int>& height) {
        int res =0;
        int left = 0;
        int right = height.size()-1;

        int curArea = 0;

        while (left<right)
        {
            curArea = min(height[left], height[right]) * (right - left);
            res = curArea > res ? curArea : res;
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};