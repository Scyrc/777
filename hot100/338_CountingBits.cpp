//
// Created by sc on 2023/4/5.
//
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        res[0] = 0;
        for (int i = 1; i <=n; ++i) {
            if((i&1) == 0) res[i] = res[i>>1];
            else res[i] = res[i-1] + 1;
        }
        return res;
    }
};