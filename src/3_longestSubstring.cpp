#include<map>
#include<math.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;

        map<char, int> cacheMap;
        for(int start=0, end=0; end<n;end++)
        {
            char element = s[end];
            if(cacheMap.count(element) > 0)
            {
                start = max(cacheMap[element], start);
            }
            ans = max(ans, end - start +1);
            cacheMap.insert(element, end+1);
        }

        return ans;
    }
};