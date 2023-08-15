//
// Created by sc on 2023/4/23.
//

#include <vector>
#include <queue>
using std::deque;
using std::queue;

using std::vector;

class MaxQueue {
private:
    deque<int> cache;
    queue<int> q;
public:
    MaxQueue() {

    }

    int max_value() {
        return cache.empty() ? -1 : cache.front();
    }

    void push_back(int value) {
        q.push(value);

        while (!cache.empty() && value > cache.back()) cache.pop_back();
        cache.push_back(value);
    }

    int pop_front() {
        if(q.empty()) return -1;
        int val = q.front();
        if(val == cache.front()) cache.pop_front();
        q.pop();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */