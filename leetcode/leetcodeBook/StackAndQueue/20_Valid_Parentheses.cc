//
// Created by sc on 2023/8/25.
//
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> cacheStack;

        for(auto& c : s)
        {
            if(c == '(' || c == '[' || c == '{')
            {
                cacheStack.push(c);
            }
            else
            {
                if(cacheStack.size() == 0) return false;
                else if( c == ')' && cacheStack.top() == '(')
                    cacheStack.pop();
                else if( c == ']' && cacheStack.top() == '[')
                    cacheStack.pop();
                else if( c == '}' && cacheStack.top() == '{')
                    cacheStack.pop();
                else return false;
            }
        }

        return cacheStack.empty();
    }
};