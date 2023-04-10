//
// Created by sc on 2023/4/10.
//
#include <stack>
using std::stack;
class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {}

    void appendTail(int value) {
        stack1.push(value);
    }

    int deleteHead() {
        if(stack1.empty()) return -1;
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }

        int res = stack2.top();
        stack2.pop();
        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */