//
// Created by sc on 2023/2/23.
//

/*给你一个字符串 s，找到 s 中最长的回文子串。
如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。*/
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s == nullptr || s.size()==0) return "";
        int left=0, right =0, maxLen=0,  len=1, maxStart =0;
        for(int i=0;i<s.size();i++)
        {
            left = i - 1;
            right = i+ 1;
            while (left>=0 && s[left] == s[i])
            {
                len++;
                left--;
            }
            while (right<s.size() && s[right] == s[i])
            {
                len++;
                right++;
            }
            while (left>=0 && right<s.size() && s[right] == s[left])
            {
                len += 2;
                left--;
                right++;
            }

            if(len > maxLen)
            {
                maxLen = len;
                maxStart = left;
            }

            len = 1;
        }

        return s.substr(maxStart+1,maxLen);

    }
};