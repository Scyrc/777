//
// Created by sc on 2023/4/2.
//

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v)
        {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });

        int len = people.size();
        vector<vector<int>> res;
        for (int i = 0; i < len; ++i)
        {
            if(people[i][1] >= i)
                res.push_back(people[i]);
            else
                res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};