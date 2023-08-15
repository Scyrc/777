//
// Created by sc on 2023/2/27.
//

#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool IsMatch(char a, char b)
    {
        if(a == '(' && b== ')') return true;
        if(a == '[' && b== ']') return true;
        if(a == '{' && b== '}') return true;
        return false;
    }
    bool isValid(string s) {
        if(s.size() % 2 > 0) return false;
        stack<char> cacheStack;
        for(auto c : s)
        {
            if(cacheStack.empty())
            {
                cacheStack.push(c);
            }
            else
            {
                char tmp = cacheStack.top();
                if(IsMatch(tmp, c))
                {
                    cacheStack.pop();
                }
                else
                {
                    cacheStack.push(c);
                }
            }
        }

        return cacheStack.empty();

    }
};