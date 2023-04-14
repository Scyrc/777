//
// Created by sc on 2023/4/14.
//

#include<stack>
#include<vector>

using std::stack;
using std::vector;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> cacheStack;
        int i = 0;
        for(int x : pushed)
        {
            cacheStack.push(x);
            while (!cacheStack.empty() && cacheStack.top() == popped[i])
            {
                cacheStack.pop();
                ++i;
            }
        }
        return cacheStack.empty();
    }
};