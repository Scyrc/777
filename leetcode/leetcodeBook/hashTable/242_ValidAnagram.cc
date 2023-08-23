//
// Created by sc on 2023/8/23.
//
#include <array>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        array<int, 26> arr{0};

        for(int i =0;i <s.size();++i)
        {
            arr[s[i] - 'a'] += 1;
            arr[t[i] - 'a'] -= 1;
        }

        for(auto& v : arr)
        {
            if(v != 0) return false;
        }
        return true;
    }
};