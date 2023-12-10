//
// Created by sc on 2023/9/18.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int i = 0, j = 0;

        for (i= 0; i< s.size() && j < g.size(); ++i)
        {
            if(s[i] >= g[j])
            {
                ++j;
            }
        }

        return j;
    }
};