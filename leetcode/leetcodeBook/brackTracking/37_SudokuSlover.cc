//
// Created by sc on 2023/9/16.
//

#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(const int& row, const int& col, const char& k, vector<vector<char>>& board)
    {
        for (int i = 0; i < col; ++i)
        {
            if(board[row][i] == k) return false;
        }

        for (int j = 0; j < row; ++j)
        {
            if(board[j][col] == k) return false;
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; ++i)
        {
            for (int j = startCol; j < startCol + 3; ++j)
            {
                if(board[i][j] == k) return false;
            }
        }
        return true;
    }
    bool backTracking(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == '.')
                {
                    for (char k = '1'; k <='9'; ++k)
                    {
                        if(isValid(i, j, k, board))
                        {
                            board[i][j] = k;
                            if(backTracking(board)) return true;
                            board[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        backTracking(board);
    }
};