//
// Created by sc on 2023/3/1.
//
#include <string>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> cacheStack;
        int res = 0;
        cacheStack.push(-1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                cacheStack.push(i);
            }
            else
            {
                cacheStack.pop();
                if(cacheStack.empty())
                {
                    cacheStack.push(i);
                }
                else
                {
                    res = max(res, i - cacheStack.top());
                }
            }
        }
        return res;
    }
};
