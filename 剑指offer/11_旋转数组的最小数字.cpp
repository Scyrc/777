//
// Created by sc on 2023/4/10.
//
#include <vector>
using std::vector;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size() == 0) return 0;
        if(numbers.size() == 1) return numbers[0];

        for (int i = 0; i < numbers.size() - 1; ++i) {
            if(numbers[i] > numbers[i+1]) return numbers[i+1];
        }
        return numbers[0];
    }
};