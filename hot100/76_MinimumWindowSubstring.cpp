//
// Created by sc on 2023/3/8.
//
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cacheMap;
        for(auto c : t)
        {
            cacheMap[c] += 1;
        }
        int count = t.size();
        int l = 0, r = 0, minSize= INT_MAX;
        int start = 0;

        while (r < s.size())
        {
            char c = s[r];
            if(cacheMap[c] > 0) count--;
            cacheMap[c] --;
            if(count == 0)
            {
                while (l<r && cacheMap[s[l]] <0)
                {
                    cacheMap[s[l]] ++;
                    l++;
                }
                if(r-l+1 < minSize)
                {
                    minSize = r-l+1;
                    start = l;
                }
                cacheMap[s[l]] ++;
                count++;
                l++;
            }
            r++;
        }

        return minSize == INT_MAX ? "" : s.substr(start, minSize);
    }
};

int main ()
{
    Solution S;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<S.minWindow(s, t);
}