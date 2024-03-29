//
// Created by sc on 2023/4/10.
//

#include <iostream>
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n > 0)
        {
            if(n & 1) ++res;
            n >>= 1;
        }
        return res;
    }
};