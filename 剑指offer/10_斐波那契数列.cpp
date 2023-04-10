//
// Created by sc on 2023/4/10.
//

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int first = 0, second = 1, third = 1;
        for (int i = 2; i <= n; ++i) {
            third = (first + second) % 1000000007;
            first = second;
            second = third;
        }
        return third;
    }
};