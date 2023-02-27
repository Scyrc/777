//
// Created by sc on 2023/2/27.
//

#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> res;
        int len = digits.size();
        if(len == 0) return res;
        vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        queue<string> cacheQueue;
        for(int i=0;i<digits.size();i++)
        {
            string letters = phone[digits[i] - '2'];
            if(0==i)
            {
                string temp;
                for(auto x : letters)
                {
                    string s(1, x);
                    cacheQueue.push(s);
                }
            }
            else
            {
                int qSize = cacheQueue.size();
                int j=0;
                while(j<qSize)
                {
                    j++;
                    string tmp = cacheQueue.front();
                    cacheQueue.pop();
                    for(auto x : letters)
                    {
                        string s(1, x);

                        cacheQueue.push(tmp + s);
                    }
                }
            }
        }

        while (!cacheQueue.empty())
        {
            res.push_back(cacheQueue.front());
            cacheQueue.pop();
        }

        return res;


    }
};