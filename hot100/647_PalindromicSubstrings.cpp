//
// Created by sc on 2023/4/2.
//

#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(), false));

        int res = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            for (int i = 0; i <= j; ++i)
            {
                if(s[i] == s[j] && (j-i<2 || dp[i+1][j-1]))
                {
                    dp[i][j] = true;
                    ++res;
                }
            }
        }
        return res;
    }
};