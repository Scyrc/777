//
// Created by sc on 2023/4/22.
//
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0) return s;
        vector<string> cache;
        string tmp = "";
        for (auto& c : s)
        {
            if(c == ' ' && tmp!= "")
            {
                cache.push_back(tmp);
                tmp = "";
            }
            else if(c != ' ') tmp += c;
        }
        if(tmp != "")   cache.push_back(tmp);
        if(cache.size() == 0) return "";

        std::reverse(cache.begin(), cache.end());
        string res = "";
        for(auto& item : cache)
        {
            res += item;
            res += ' ';
        }
        return res.erase(res.size()-1, 1);
    }
};