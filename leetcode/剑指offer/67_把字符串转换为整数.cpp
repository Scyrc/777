//
// Created by sc on 2023/4/24.
//

#include <string>
using std::string;

class Solution {
public:
    int strToInt(string str) {
        int res = 0;
        int i = 0, sign = 1, length = str.size();
        if(length == 0) return 0;

        while (str[i] == ' ')
            if(++i == length) return 0;
        
        if(str[i] == '-') sign = -1;
        if(str[i] == '-' || str[i] == '+') ++i;

        for (int j = i; j < length; ++j) {
            if(str[j] < '0' || str[j] > '9') break;
            int digit = str[j] - '0';
            if(res > (INT_MAX - digit) / 10)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res*10 + digit;
        }

        return res*sign;
    }
};