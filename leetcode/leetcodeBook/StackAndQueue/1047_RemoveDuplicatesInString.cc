//
// Created by sc on 2023/8/25.
//
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> cacheStack;

        for(auto&c : s)
        {
            if(cacheStack.empty())
            {
                cacheStack.push(c);
            }
            else
            {
                if(c == cacheStack.top())
                {
                    cacheStack.pop();
                }
                else
                {
                    cacheStack.push(c);
                }
            }
        }

        string res = "";

        while (!cacheStack.empty())
        {
            res += cacheStack.top();
            cacheStack.pop();
        }

        std::reverse(res.begin(), res.end());

        return res;
    }
};