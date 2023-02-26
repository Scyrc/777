//
// Created by sc on 2023/2/26.
//

#include <vector>
using namespace  std;
#include <string>

class Solution_01 {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<int> cache(nums.size(), 0);
        for(int i =1;i<nums.size();i++)
        {
            cache[i] = cache[i-1] + nums[i-1];
        }
        int sum = cache[nums.size() - 1] + nums[nums.size() - 1];
        for(int i =0; i<nums.size();i++)
        {
            res[i] = abs(cache[i] - (sum - cache[i] - nums[i]));
        }
        return res;
    }
};
class Solution_02 {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long curVal = word[0] - '0';
        vector<int> res(word.size(),0);
        bool flag = false;
        for(int i=0;i<word.size();i++)
        {

            if(i>0)
            {
                if(flag)
                {
                    curVal =  word[i] - '0';
                }
                else
                {
                    curVal = curVal*10 + word[i] - '0';
                }
                flag = false;
            }
            if(curVal % m == 0)
            {
                res[i] = 1;
                flag = true;
            }
            else
            {
                flag = false;
                curVal = curVal % m;
            }
        }

        return res;
    }
};

class Solutio_03 {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int res =0;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        bool flag = true;
        int k = len / 2;
        int cur = 0;
        while (flag && nums.size() >= 2 && cur < len / 2)
        {
            flag = false;
            int min = nums[cur];  // min item
            while(k < len)
            {
                if(2*min <= nums[k])
                {
                    flag = true;
                    res += 2;
                    cur += 1;
                    k+= 1;
                    break;
                }
                k+= 1;
            }
        }
        return res;
    }
};