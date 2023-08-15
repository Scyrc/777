//
// Created by sc on 2023/4/23.
//

#include <vector>
using std::vector;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> pre(6, 1/6.0);

        for (int i = 2; i <=n; ++i) {
            vector<double> tmp(5*i+1, 0);
            for (int j = 0; j < pre.size(); ++j) {
                for (int k = 0; k < 6; ++k) {
                    tmp[j+k] += pre[j]/6.0;
                }
            }
            pre = tmp;
        }
        return pre;
    }
};