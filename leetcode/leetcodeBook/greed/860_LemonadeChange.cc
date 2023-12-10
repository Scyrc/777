//
// Created by sc on 2023/9/18.
//
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five =0, ten = 0, twenty = 0;
        for(const int& bill : bills)
        {
            if(bill == 5) ++five;

            else if(bill == 10)
            {
                if(five == 0) return false;
                --five;
                ++ten;
            }
            else if(bill == 20)
            {
                if(five > 0 && ten > 0)
                {
                    --five;
                    --ten;
                }
                else if(five > 2)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};