//
// Created by sc on 2023/8/25.
//

#include <queue>
using namespace std;
class MyStack {
private:
    queue<int> cacheQueue;
public:
    MyStack() {

    }

    void push(int x) {
        cacheQueue.push(x);
    }

    int pop() {
        int size = cacheQueue.size();
        while (size> 1)
        {
            cacheQueue.push(cacheQueue.front());
            cacheQueue.pop();
            --size;
        }
        int res = cacheQueue.front();
        cacheQueue.pop();
        return  res;
    }

    int top() {
        return cacheQueue.back();
    }

    bool empty() {
        return cacheQueue.empty();
    }
};