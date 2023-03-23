//
// Created by sc on 2023/3/23.
//

#include <vector>
#include <iostream>
using namespace std;
class MinStack {
public:
    vector<int> Currentvector;
    vector<int> Minvector;
    int min;
    MinStack() {
        min = INT_MAX;
    }

    void push(int val) {
        Currentvector.push_back(val);
        if(Minvector.empty() || Minvector.back() >= val)
        {
            Minvector.push_back(val);
        }
    }

    void pop() {
        if(Currentvector.back() == Minvector.back())
        {
            Minvector.pop_back();
        }
        Currentvector.pop_back();
    }

    int top() {
        return Currentvector.back();
    }

    int getMin() {
        return Minvector.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */