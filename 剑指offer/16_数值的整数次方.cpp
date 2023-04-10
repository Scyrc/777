//
// Created by sc on 2023/4/10.
//


class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1.0 ||  x == 0.0) return x;
        if(n == 0) return 1.0;
        if(n == 1) return x;
        bool flag = false;
        long b = n;
        if(b<0)
        {
            flag = true;
            b  = -1*b;
        }
        double res = 1.0;
        while (b > 0)
        {
            if((b & 1) == 1) res*= x;
            x *= x;
            b >>= 1;
        }
        return flag ? 1.0 / res : res;
    }
};