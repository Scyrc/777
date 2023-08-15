//
// Created by sc on 2023/4/10.
//
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<vector<char>>cacheBoard;
    int m;
    int n;
    bool res = false;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(board[i][j] == word[0])
                {
                    cacheBoard = board;
                    dfs(word, i, j);
                    if(res) return true;
                }
            }

        }
        return false;
    }

    void dfs(string word, int i, int j)
    {
        if(cacheBoard[i][j] == word[0])
        {
            char tmp = cacheBoard[i][j];
            cacheBoard[i][j] = '*';
            word.erase(word.begin());
            if(word.size() == 0)
            {
                res = true;
                return;
            }
            if(i<m-1) dfs(word, i+1, j);
            if(res) return;
            if(i>0) dfs(word, i-1, j);
            if(res) return;
            if(j>0) dfs(word, i, j-1);
            if(res) return;
            if(j<n-1) dfs(word, i, j+1);
            if(res) return;

            cacheBoard[i][j] = tmp;
            word.insert(word.begin(), tmp);
        }
    }
};