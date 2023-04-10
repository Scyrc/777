//
// Created by sc on 2023/4/10.
//
class Solution {
public:
    int cuttingRope(int n) {
        if(n<4) return n-1;
        unsigned long long res = 1;
        while (n > 4)
        {
            res *= 3;
            n -= 3;
        }
        return n*res;
    }
};