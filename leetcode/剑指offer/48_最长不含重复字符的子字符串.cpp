//
// Created by sc on 2023/4/17.
//

#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> cacheMap;
        for(int start = 0, end = 0; end < s.size() ; ++end)
        {
            char item  = s[end];
            if(cacheMap.count(item))
                start = std::max(start, cacheMap[item]+1);

            res = std::max(res, end - start + 1);
            cacheMap[item] = end;
        }
        return res;
    }
};