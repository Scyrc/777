//
// Created by sc on 2023/3/6.
//

#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> cacheMap;

        for(auto &x : strs)
        {
            auto tmp = x;
            sort(x.begin(), x.end());
            if(cacheMap.count(x) == 0)
            {
                vector<string> t {tmp};
                cacheMap[x] = t;
            }
            else
            {
                cacheMap[x].push_back(tmp);
            }
        }
        vector<vector<string>> res;

        for(auto x : cacheMap)
        {
            res.push_back(x.second);
        }
        return res;
    }
};