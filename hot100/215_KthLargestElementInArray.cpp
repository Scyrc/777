//
// Created by sc on 2023/3/26.
//
#include <vector>
#include <random>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int targetIndex = len - k;
        int left = 0;
        int right = len -1;
        while(true)
        {
            int pivotIndex = partition(nums, left, right);
            if(pivotIndex == targetIndex) return nums[pivotIndex];
            else if(pivotIndex < targetIndex) left = pivotIndex + 1;
            else right = pivotIndex - 1;
        }
    }

    int partition(vector<int>& nums, int left, int right)
    {
        default_random_engine e;
        uniform_int_distribution<unsigned> u(left, right);
        int randomIndex = u(e);
        swap(nums[left], nums[randomIndex]);
        int pivot = nums[left];
        int l = left + 1;
        int r = right;

        while (true)
        {
            while (l<=r && nums[l] < pivot) ++l;
            while (l<=r && nums[r] > pivot) --r;
            if(l>=r) break;
            swap(nums[l++], nums[r--]);
        }

        swap(nums[left], nums[r]);
        return r;
    }
};

int main()
{   vector<int> nums{3,2,1,5,6,4};
    Solution S;
    cout<<S.findKthLargest(nums, 2)<<endl;
}