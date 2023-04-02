//
// Created by sc on 2023/4/2.
//


class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z)
        {
            res += z&1;
            z >>= 1;
        }
        return res;
    }
};