//
// Created by sc on 2023/8/23.
//
#include <string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();


        /*if(s.substr(0, size / 2) == s.substr(size / 2 + 1, size / 2))
        {
            return true;
        }*/

        int repeatNum = 2;
        while (repeatNum <= size)
        {
            if(size % repeatNum == 0)
            {
                int subStingLen = size / repeatNum;

                if(s == s.substr(subStingLen, size - subStingLen) + s.substr(0, subStingLen))
                {
                    return true;
                }
            }
        }
        return false;

    }
};