//
// Created by sc on 2023/4/16.
//

#include <queue>
#include <vector>
using std::queue;
using std::priority_queue;
using std::vector;
class MedianFinder {
private:
    priority_queue<int, vector<int>,std::less<int>> queMin;
    priority_queue<int, vector<int>,std::greater<int>> queMax;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if(queMin.empty() || num < queMin.top())
        {
            queMin.push(num);
            if(queMin.size() > queMax.size() + 1)
            {
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else
        {
            queMax.push(num);
            if(queMax.size() > queMin.size())
            {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
    }

    double findMedian() {
        if(queMin.size() > queMax.size()) return queMin.top();
        else return (queMin.top() + queMax.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */