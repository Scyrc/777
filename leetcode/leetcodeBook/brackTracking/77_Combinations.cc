//
// Created by sc on 2023/9/3.
//
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backTracking(int n, const int& k, int startIndex)
    {
        if(path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - k + path.size() + 1 ; ++i)
        {
            path.push_back(i);
            backTracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backTracking(n, k, 1);
        return res;
    }
};