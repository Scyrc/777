    //
    // Created by sc on 2023/3/7.
    //

    #include <vector>
    using namespace std;
    class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            //vector<vector<int>> dp(m, vector<int>(n, 0));
            for(int i = 0;i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    int minSum = grid[i][j];
                    if(i>0 && j>0)
                    {
                        minSum += min(grid[i-1][j] , grid[i][j-1]);
                    }
                    else if(i>0)
                    {
                        minSum += grid[i-1][j];
                    }
                    else if(j>0)
                    {
                        minSum += grid[i][j-1];
                    }
                    grid[i][j] = minSum;
                }
            }
            return grid[m-1][n-1];

        }
    };