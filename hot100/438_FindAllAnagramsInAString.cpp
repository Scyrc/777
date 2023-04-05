//
// Created by sc on 2023/4/5.
//

#include <vector>
#include <string>
#include <array>
using std::vector;
using std::string;
using std::array;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenS = s.size();
        int lenP = p.size();
        vector<int> res;
        if(lenS < lenP) return res;
        array<int, 26> countArr{};
        int diff = 0;
        for(int i=0;i<lenP;++i)
        {
            ++countArr[s[i]-'a'];
            --countArr[p[i]-'a'];
        }
        for(const int& x : countArr) diff = x != 0 ? diff+1 : diff;
        if(diff == 0) res.push_back(0);

        for(int i=0; i<lenS - lenP; ++i)
        {
            if(countArr[s[i]- 'a'] == 1) --diff;
            if(countArr[s[i]- 'a'] == 0) ++diff;
            --countArr[s[i]- 'a'];

            if(countArr[s[i+lenP]- 'a'] == -1) --diff;
            if(countArr[s[i+lenP]- 'a'] == 0) ++diff;
            ++countArr[s[i+lenP]- 'a'];

            if(diff == 0) res.push_back(i+1);
        }
        return res;
    }
};

int main()
{
    Solution S;
    S.findAnagrams("cbaebabacd", "abc");
}