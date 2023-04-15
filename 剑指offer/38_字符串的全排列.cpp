//
// Created by sc on 2023/4/15.
//

#include <vector>
#include <string>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_set;

class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        string select = "";
        dfs(select, s);
        return res;
    }

    void dfs(string& select, string& candi)
    {
        if(candi.size() == 0)  res.push_back(select);
        unordered_set<char> cacheSet;
        int i =-1;
        int len = candi.size();
        while (++i<len)
        {
            char candiChar = candi[i];
            candi.erase(candi.begin()+i);
            if(cacheSet.count(candiChar) == 0) // 剪枝
            {
                cacheSet.insert(candiChar);
                select.push_back(candiChar);
                dfs(select, candi);
                select.pop_back();
            }
            candi.insert(candi.begin()+i, candiChar);
        }
    }
};