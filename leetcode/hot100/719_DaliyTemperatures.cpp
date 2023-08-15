//
// Created by sc on 2023/3/31.
//

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> res(len, 0);
        vector<pair<int, int>> cacheVector;

        for (int i = 0; i < len; ++i)
        {
            while(!cacheVector.empty() && temperatures[i] > cacheVector.back().first)
            {
                res[cacheVector.back().second] = i -cacheVector.back().second;
                cacheVector.pop_back();
            }
            cacheVector.push_back(make_pair(temperatures[i], i));
        }
        return res;
    }
};
int main()
{
    vector<int> v{73,74,75,71,69,72,76,73};
    Solution S;
    S.dailyTemperatures(v);
}