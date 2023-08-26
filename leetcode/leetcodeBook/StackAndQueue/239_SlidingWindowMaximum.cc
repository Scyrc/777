//
// Created by sc on 2023/8/26.
//
#include <vector>
#include <deque>
using namespace std;
class Solution {
    class MyDeque
    {
    private:
        deque<int> cacheDeque;

    public:
        void pop(int value)
        {
            if (!cacheDeque.empty() && cacheDeque.front() == value)
                cacheDeque.pop_front();
        }

        void push(int value)
        {
            while (!cacheDeque.empty() && cacheDeque.back() < value)
            {
                cacheDeque.pop_back();
            }
            cacheDeque.push_back(value);
        }

        int front()
        {
            if(!cacheDeque.empty())
                return cacheDeque.front();

            return -1;
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        MyDeque myDeque;
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            myDeque.push(nums[i]);
        }
        res.push_back(myDeque.front());

        for (int i = k; i < nums.size(); ++i) {
            myDeque.pop(nums[i - k]);
            myDeque.push(nums[i]);
            res.push_back(myDeque.front());
        }
        return res;
    }
};