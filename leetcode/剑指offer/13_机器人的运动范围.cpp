//
// Created by sc on 2023/4/25.
//
#include <iostream>
#include <math.h>
#include <vector>
using std::vector;

class Solution {
private:
    int maxSide;
    int row;
    int col;
    int res = 0;
    vector<vector<int>> cache;
public:
    int movingCount(int m, int n, int k) {
        row = m;
        col = n;
        maxSide = k;
        cache = vector(m, vector<int>(n, 0));

        dfs(0, 0);
        return res;
    }
    int digitSum(int num)
    {
        int ans = 0;
        while (num >= 10)
        {
            ans += num % 10;
            num /= 10;
        }
        return ans + num;
    }
    void dfs(int i, int j)
    {
        if(i<0 || i >= row || j < 0 || j >= col) return;
        if(cache[i][j] == -1) return;
        if(digitSum(i) + digitSum(j) > maxSide) return;
        cache[i][j] = -1;
        ++res;
        dfs(i + 1, j);
        //dfs(i - 1, j);
        dfs(i, j + 1);
        //dfs(i, j - 1);
    }
};

int main()
{
    Solution s;
    std::cout<<s.digitSum(111)<<std::endl;
    std::cout<<s.digitSum(123)<<std::endl;
    std::cout<<s.digitSum(100)<<std::endl;

}