#include <map>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> CacheMap;
        vector<int> res(2, -1);
        for(int i=0; i<nums.size(); ++i)
        {
            if(CacheMap.count(target - nums[i]) > 0)
            {
                res[0] = i;
                res[1] = CacheMap[target - nums[i]];
                return res;
            }
            CacheMap[nums[i]] = i;
        }
        return res;
    }
};

int main()
{
    std::cout<<"0";
    return 0;
}