//
// Created by sc on 2023/8/25.
//
#include <math.h>
#include<string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
protected:
    bool isDigit(string s)
    {
        return s != "+" && s != "-" && s != "*" && s != "/";
    }
    int getDigit(string s)
    {
        int index = 0;
        bool isPositive = true;
        if(s[0] == '-')
        {
            index = 1;
            isPositive = false;
        }
        int size = s.size();
        int value = 0;
        while (index < size)
        {
            value += (s[index] - '0')* pow(10, s.size() - 1 -index);
            ++index;
        }

        return isPositive ? value : -value;
    }

    int getValue(int a, int b, string s)
    {
        if(s == "+")
        {
            return a + b;
        }
        else if(s == "-")
        {
            return a - b;
        }
        else if(s == "*")
        {
            return a * b;
        }
        else if(s == "/")
        {
            return a / b;
        }
        return a;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> cacheStack;

        for(auto& s : tokens)
        {
            if(isDigit(s))
            {
                cacheStack.push(getDigit(s));
            }
            else
            {
                int a = cacheStack.top();
                cacheStack.pop();
                int b = cacheStack.top();
                cacheStack.pop();

                cacheStack.push(getValue(b, a, s));
            }
        }
        return cacheStack.top();
    }
};