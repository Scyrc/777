//
// Created by sc on 2023/4/25.
//

#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
class Solution {
public:
    string minNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) ->bool{
            string  aStr = std::to_string(a);
            string  bStr = std::to_string(b);
            return aStr + bStr < bStr + aStr;
        });
        string res = "";
        for(auto&& x : nums)
        {
            res += std::to_string(x);
        }

        return res;
    }
};
