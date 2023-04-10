//
// Created by sc on 2023/4/10.
//

class Solution {
public:
    int numWays(int n) {
        if(n<=1) return 1;
        int first = 1, second = 1, third = 2;
        for (int i = 2; i <= n; ++i) {
            third = (first + second) % 1000000007;
            first = second;
            second = third;
        }
        return third;
    }
};