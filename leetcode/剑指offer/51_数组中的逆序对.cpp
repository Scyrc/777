//
// Created by sc on 2023/4/20.
//

#include <vector>
using std::vector;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size()-1, nums, tmp);
    }

private:
    int mergeSort(int l, int r, vector<int>& nums, vector<int>& tmp)
    {
        if(l>=r) return 0;

        int m = (l+r) / 2;

        int res = mergeSort(l, m, nums, tmp) + mergeSort(m+1, r, nums, tmp);

        for(int k = l; k<=r;++k) tmp[k] = nums[k];

        int i = l, j = m+1;

        for (int k = l; k <= r; ++k) {
            if(i == m+1)   //左边合并完毕
            {
                nums[k] = tmp[j++];
            }
            else if(j == r+1 || tmp[i]<=tmp[j]) //右边合并完毕 或 左边小于右边
            {
                nums[k] = tmp[i++];
            }
            else // nums[i] > nums[j]
            {
                nums[k] = tmp[j++];
                res += m - i + 1;
            }
        }

        return res;
    }
};