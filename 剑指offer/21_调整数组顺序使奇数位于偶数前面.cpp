//
// Created by sc on 2023/4/11.
//
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            while(nums[l] % 2 == 1 && l<r) ++l;
            while(nums[r] % 2 == 0 && l<r) --r;
            std::swap(nums[l++], nums[r--]);
        }

        return nums;
    }
};

int main()
{
    vector<int> x {1,5,3,11,13,11,11,1,12,18,16,8,1,5,16,2};
    Solution s;
    s.exchange(x);
}