//
// Created by sc on 2023/3/23.
//
#include <vector>
using namespace std;

class Solution{
public:
    int n;
    int m;
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0 || i>n-1 || j<0 || j>m-1 || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++ res;
                }
            }
        }
        return res;
    }
};


int main()
{
    vector<vector<char>> grid;
    grid.push_back(vector<char>{'1', '1', '1', '1', '0'});
    grid.push_back(vector<char>{'1', '1', '0', '1', '0'});
    grid.push_back(vector<char>{'1', '1', '0', '0', '0'});
    grid.push_back(vector<char>{'0', '0', '0', '0', '0'});

    Solution S;
    S.numIslands(grid);
}