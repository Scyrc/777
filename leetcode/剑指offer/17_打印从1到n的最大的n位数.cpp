//
// Created by sc on 2023/4/10.
//

#include <vector>
#include <math.h>
using std::vector;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res(std::pow(10, n) -1 , 0);
        for (int i = 0; i < std::pow(10, n) - 1; ++i) {
            res[i] = i + 1;
        }
        return res;
    }
};