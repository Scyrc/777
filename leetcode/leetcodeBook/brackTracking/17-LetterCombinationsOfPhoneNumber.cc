//
// Created by sc on 2023/9/5.
//
#include <string>
#include<vector>
using namespace std;
class Solution {
private:

    vector<string> res;
    string path;
    vector<string> assicArr = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };
    void backTracking(const int& startIndex, const string& digits)
    {
        if(path.size() == 4)
        {
            res.push_back(path);
        }

        for (int i = startIndex; i < digits.size(); ++i)
        {
            string str = assicArr[digits[i] - '2'];
            for (int j = 0; j < str.size(); ++j)
            {
                path.push_back(str[j]);
                backTracking(startIndex + 1, digits);
                path.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits)
    {
        backTracking(0, digits);
        return res;
    }
};