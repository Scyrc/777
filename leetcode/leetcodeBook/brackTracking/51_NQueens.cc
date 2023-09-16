//
// Created by sc on 2023/9/16.
//
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
    vector<vector<string>> res;
    vector<int> availableCols;

private:
    bool isValid(int row, int col, vector<string>& chessBoard, int n)
    {
        for (int i = 0; i < row; ++i) {
            if(chessBoard[i][col] == 'Q')
                return false;
        }

        for (int i = row-1, j = col - 1; i>=0 && j>=0; --i, --j)
        {
            if(chessBoard[i][j] == 'Q')
                return false;
        }

        for (int i = row-1, j = col + 1; i>=0 && j<n; --i, ++j)
        {
            if(chessBoard[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void backTracking(const int& currRow, const int& n, vector<string>& chessBoard)
    {
       if(currRow == n)
       {
           res.push_back(chessBoard);
           return;
       }

        for (int col = 0; col < n; ++col)
        {
            if(isValid(currRow, col, chessBoard, n))
            {
                chessBoard[currRow][col] = 'Q';
                backTracking(currRow + 1, n, chessBoard);
                chessBoard[currRow][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<string> chessBoard(n, string(n, '.'));
        backTracking(0, n, chessBoard);
        return res;
    }
};