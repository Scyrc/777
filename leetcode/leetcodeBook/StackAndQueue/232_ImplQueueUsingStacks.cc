//
// Created by sc on 2023/8/25.
//
#include <stack>
using namespace std;
class MyQueue {
private:
    stack<int> cacheStack1;
    stack<int> cacheStack2;

public:
    MyQueue() {

    }

    void push(int x) {
        cacheStack1.push(x);
    }

    int pop() {
        if(!cacheStack2.empty())
        {
           int res = cacheStack2.top();
           cacheStack2.pop();
           return res;
        }
        while (!cacheStack1.empty())
        {
            cacheStack2.push(cacheStack1.top());
            cacheStack1.pop();
        }

        int res = cacheStack2.top();
        cacheStack2.pop();
        return res;
    }

    int peek() {
        if(!cacheStack2.empty())
        {
            return cacheStack2.top();
        }
        while (!cacheStack1.empty())
        {
            cacheStack2.push(cacheStack1.top());
            cacheStack1.pop();
        }
        return cacheStack2.top();
    }

    bool empty() {
        return cacheStack1.empty() && cacheStack2.empty();
    }
};