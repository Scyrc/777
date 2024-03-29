//
// Created by sc on 2023/3/23.
//
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int select = nums[0];
        int count = 1;
        for(int i = 1; i< nums.size(); ++i)
        {
            if(select == nums[i]) ++count;
            else if(--count == 0)
            {
                select = nums[i];
                count = 1;
            }
        }
        return select;
    }
};