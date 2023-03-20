//
// Created by sc on 2023/3/20.
//
#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

class Solution {
public:
    /*bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
       for(auto& word :  wordDict)
       {
           if(s.substr(0, word.size()) == word)
           {
               string tmp = s;
               s = s.substr(word.size(), s.size() - word.size());
               if(wordBreak(s, wordDict))
               {
                   return true;
               }
               else
               {
                   s = tmp;
               }
           }
       }

        return false;
    }*/

    bool wordBreak(string s, vector<string>& wordDict)
    {
        const  unsigned long long len = s.size();

        vector<bool> dp(len+1, false);
        dp[0] = true;
        for(int i =1;i<=len;++i)
        {
            for(int j = i-1; j>=0;--j)
            {
                if(dp[i]) break;
                if(!dp[j]) continue;
                const string x = s.substr(j, i-j);
                if(std::find(wordDict.begin(), wordDict.end(),x) != wordDict.end() && dp[j] == true)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

int main()
{
    vector<string> wordDict{"leet", "code"};
    Solution S;
    std::cout<<S.wordBreak("leetcode", wordDict);
}