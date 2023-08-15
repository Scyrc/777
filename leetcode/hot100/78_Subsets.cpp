//
// Created by sc on 2023/3/9.
//

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(vector<int>());
        help(vector<int>(), nums);
        return res;
    }

    void help(vector<int> select, vector<int> options)
    {
        while (options.size() > 0)
        {
            select.push_back(options.front());
            res.push_back(select);
            options.erase(options.begin());
            help(select, options);
            select.pop_back();
        }
    }

};