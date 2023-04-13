//
// Created by sc on 2023/4/13.
//
#include <vector>
using std::vector;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> fullVector;
    vector<int> minVector;
    MinStack() {
    }

    void push(int x) {
        fullVector.push_back(x);
        if(minVector.empty() || x <= minVector.back())
        {
            minVector.push_back(x);
        }
    }

    void pop() {
        if(fullVector.back() == minVector.back()) minVector.pop_back();
        fullVector.pop_back();
    }

    int top() {
        return fullVector.back();
    }

    int min() {
        return minVector.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */