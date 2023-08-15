//
// Created by sc on 2023/8/15.
//

#include <vector>
#include <math.h>
using namespace  std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int resIndex = 0;
        int selectIndex;
        for (selectIndex = 0; selectIndex < nums.size(); ++selectIndex)
        {
            if(nums[selectIndex] >=0)
            {
                break;
            }
        }

        int leftOffset = selectIndex - 1;
        int rightOffset = selectIndex;

        while (leftOffset >=0 && rightOffset < nums.size())
        {
            if(std::abs(nums[leftOffset]) <= std::abs(nums[rightOffset]))
            {
                res[resIndex++] = nums[leftOffset] * nums[leftOffset];
                --leftOffset;
            }
            else
            {
                res[resIndex++] = nums[rightOffset] * nums[rightOffset];
                ++rightOffset;

            }
        }

        while (leftOffset >=0 )
        {
            res[resIndex++] =  nums[leftOffset] * nums[leftOffset];
            --leftOffset;
        }

        while (rightOffset < nums.size() )
        {
            res[resIndex++] = nums[rightOffset] * nums[rightOffset];
            ++rightOffset;
        }

        return res;
    }
};