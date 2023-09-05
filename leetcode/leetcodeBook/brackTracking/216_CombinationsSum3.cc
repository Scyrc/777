//
// Created by sc on 2023/9/5.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> res;
public:
    bool Cut(const int& startIndex, const int& k, const int target)
    {
        int min = 0;
        int max = 0;

        for (int i = 0; i < k && startIndex + i <=9;  ++i)
        {
            min += startIndex + i;
        }
        if(min > target) return true;

        for (int i = k; i > 0 && startIndex <= 9-i + 1;  --i)
        {
            max += 9-i + 1;
        }
        if(max < target) return true;

        return false;
    }
    void backTracking(int startIndex, vector<int>& select, int& k, int& target)
    {
        if(target == 0 && k == 0)
        {
            res.push_back(select);
            return;
        }

        if(k > 0)
        {
            if(Cut(startIndex, k, target))
                return;

            for (int i = startIndex; i <= 9; ++i)
            {
                if(Cut(i, k, target))
                    break;
                target -= i;
                select.push_back(i);
                --k;
                backTracking(i + 1, select, k, target);
                ++k;
                select.pop_back();
                target += i;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> select;
        backTracking(1, select, k, n);
        return res;
    }
};


int main()
{
    Solution s;
    s.combinationSum3(3, 9);
}