//
// Created by sc on 2023/2/22.
//

//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数 。
//
//算法的时间复杂度应该为 O(log (m+n))
//
//来源：力扣（LeetCode）
//链接：https://leetcode.cn/problems/median-of-two-sorted-arrays
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using namespace  std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n) return findMedianSortedArrays(nums2, nums1);

        int iMax = m, iMin = 0;
        while (iMax >= iMin)
        {
            int i = (iMin + iMax) / 2;
            int j = (m+n+1)/2 - i;
            if(j!=0 && i!=m && nums2[j-1]>nums1[i])
            {
                iMin = i + 1;
            }
            else if(i!=0 && j!=n && nums1[i-1] > nums2[j])
            {
                iMax = i - 1;
            }
            else
            {
                int maxLeft = 0;
                if(i==0)  {maxLeft = nums2[j-1];}
                else if(j==0) {maxLeft = nums1[i-1];}
                else{maxLeft = max(nums1[i-1], nums2[j-1]);}
                if((m+n)%2 == 1) return maxLeft;

                int minRight = 0;
                if(i==m)  {minRight = nums2[j];}
                else if(j==n) {minRight = nums1[i];}
                else{minRight = min(nums1[i], nums2[j]);}

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};