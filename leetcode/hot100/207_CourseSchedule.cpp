//
// Created by sc on 2023/3/24.
//

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> cacheMap;
        for(auto& x : prerequisites)
        {
            inDegree[x[0]] += 1;
            cacheMap[x[1]].push_back(x[0]);
        }

        queue<int> cacheQu;
        for (int i = 0; i < numCourses; ++i) {
            if(inDegree[i] == 0) cacheQu.push(i);
        }
        int count = 0;
        while (!cacheQu.empty())
        {
            int select = cacheQu.front();
            cacheQu.pop();
            ++count;
            vector<int> end = cacheMap[select];
            if(end.size() > 0)
            {
                for(auto& x : end)
                {
                    if(--inDegree[x] == 0)
                    {
                        cacheQu.push(x);
                    }
                }
            }
        }

        return count == numCourses;
    }
};