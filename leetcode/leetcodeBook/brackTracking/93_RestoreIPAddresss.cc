//
// Created by sc on 2023/9/8.
//
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<string> res;
    vector<string> path;
    inline bool isIpElement(const string& s, const int& curIndex,   int l)
    {
        if(l == 1)
            return true;
        if(l > 1 && s[curIndex] == '0')
            return false;
        int value = 0;
        int count = 0;
        while (l > 0)
        {
            value += (s[curIndex + count] - '0') * pow(10, --l);
            ++count;
        }
        if(value > 256)
            return false;
        return true;
    }
    bool cut(const string& s, const int& curIndex, const int& l, const int& count)
    {
        if(curIndex + l - 1 >= s.size()) return false;

        if(s.size() - (curIndex + l) < (count - 1) || s.size() - (curIndex + l) > 3*(count - 1))
            return false;

        return true;
    }
public:
    void backTracking(const string& s, const int& curIndex, const int& count)
    {
        if(path.size() == 4 && curIndex == s.size())
        {
            string ip;
            int index = 0;
            for(const auto& elem : path)
            {
                ip += elem;
                if(++index != 4)
                {
                    ip += '.';
                }
            }
            res.push_back(ip);
        }
        if(path.size() == 4)
            return;
        for (int i = 1; i < 4; ++i)
        {
            if(!path.empty() && path[0] == "25" )
            {
                cout<< "debug"<<std::endl;
            }
            if(!cut(s, curIndex, i, count))
                break;
            if( isIpElement(s, curIndex, i))
            {
                string subStr = s.substr(curIndex, i);
                path.push_back(subStr);
                backTracking(s, curIndex + i, count -1);
                path.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        if(s.size() < 4 || s.size() > 12) return res;

        backTracking(s, 0, 4);

        return res;
    }
};

int main()
{
    Solution s;
    auto t = s.restoreIpAddresses("25525511135");
    return 0;
}