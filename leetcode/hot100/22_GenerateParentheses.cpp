//
// Created by sc on 2023/2/27.
//

#include <vector>
using namespace std;
#include <string>
class Solution {
public:
    vector<string> res;
    void dfs(const string& tmp, int left, int right)
    {
        if(left<0 || left > right) return;

        if(left == 0 && right == 0)
        {
            res.push_back(tmp);
            return;
        }

        dfs(tmp + "(", left-1, right);
        dfs(tmp + ")", left, right -1);
    }
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return res;
    }
};