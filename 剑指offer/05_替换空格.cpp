//
// Created by sc on 2023/4/9.
//
#include <string>
using std::string;
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for(char& c : s)
        {
            if(c == ' ') res += "%20";
            else res += c;
        }
        return res;
    }
};