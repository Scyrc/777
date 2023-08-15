//
// Created by sc on 2023/4/17.
//
#include <array>
#include <string>
using std::string;
using std::array;
class Solution {
public:
    char firstUniqChar(string s) {
        array<int, 26> cacheArr{};

        for(auto& c : s)
        {
            cacheArr[c-'a'] += 1;
        }
        for(auto& c : s)
        {
            if(cacheArr[c-'a'] == 1) return c;
        }
        return ' ';
    }
};