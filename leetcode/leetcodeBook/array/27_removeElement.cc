//
// Created by sc on 2023/8/15.
//
#include <vector>
using namespace  std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        int endIndex = nums.size() - 1;
        int index  = 0;
        int tmp;
        while (index <= endIndex)
        {
            if(nums[index] == val)
            {
                ++res;
                while (nums[endIndex] == val)
                {
                    --endIndex;
                    if(index >= endIndex)
                    {
                        return index;
                    }
                }

                tmp = nums[endIndex];
                nums[endIndex] = val;
                nums[index] = tmp;
            }
            ++index;
        }

        return index;
    }
};

int main()
{
    vector<int> v = {0,1,2,2,3,0,4,2};
    Solution s;
    s.removeElement(v, 2);
}