//
// Created by sc on 2023/9/18.
//
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int currSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            currSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if(currSum < 0)
            {
                currSum = 0;
                start = i + 1;
            }
        }

        return totalSum < 0 ? -1 : start;
    }
};