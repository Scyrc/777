//
// Created by sc on 2023/8/23.
//

#include <unordered_set>
using namespace  std;
class Solution {
public:

    int getPowSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> cacheSet;
        cacheSet.insert(n);
        while (true)
        {
            int newVal = getPowSum(n);
            if(newVal == 1) return true;
            if(cacheSet.contains(newVal))
            {
                return false;
            }
            cacheSet.insert(newVal);

            n = newVal;
        }
    }
};