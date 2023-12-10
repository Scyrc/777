//
// Created by sc on 2023/9/19.
//
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b)
        {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        vector<vector<int>> res;

        for (int i = 0; i < people.size(); ++i) {
            if(people[i][1] >= i)
                res.emplace_back(people[i]);
            else
                res.insert(res.begin() + people[i][1], people[i]);
        }

        return res;
    }
};