//
// Created by sc on 2023/3/11.
//

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool res = false;
    int m =0;
    int n =0;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i =0;i<m;++i)
            for(int j =0;j<n;++j)
                if(board[i][j] == word[0])
                {
                    help(board, word, i, j);
                    if(res) return true;
                }
        return res;
    }

    void help(vector<vector<char>>& board, string word, int i, int j)
    {
        if(word.size() == 0) res = true;
        if(res) return;
        if(board[i][j] == word[0])
        {
            char tmp = word[0];
            board[i][j] = '*';
            word.erase(word.begin());
            if(word.size() == 0)
            {
                res = true;
                return;
            }

            if(i<m-1) help(board,  word, i+1, j);
            if(res) return;
            if(j<n-1) help(board,  word, i, j+1);
            if(res) return;
            if(i>0) help(board,  word, i-1, j);
            if(res) return;
            if(j>0) help(board,  word, i, j-1);
            if(res) return;
            board[i][j] = tmp;
            word.insert(word.begin(), tmp);
        }
    }
};