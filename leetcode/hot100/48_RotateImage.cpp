//
// Created by sc on 2023/3/5.
//

#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int level = (len+1)/2;
        int curRow = 0;
        int curLine = 0;
        for(int i=0;i<level;i++)
        {
            curRow = i;
            for(int j =i;j<len-1-i;j++)
            {
                curLine = j;
                int lastVal = matrix[curRow][curLine];
                int k=0;
                while (k<4)
                {
                    int nextRow = curLine;
                    int nextLine = len - curRow - 1;
                    int temp = matrix[nextRow][nextLine];
                    matrix[nextRow][nextLine] = lastVal;
                    lastVal = temp;
                    curRow = nextRow;
                    curLine = nextLine;
                    ++k;
                }
            }
        }
    }
};