//
// Created by sc on 2023/4/22.
//

#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return   s.substr(n, s.size() - n) + s.substr(0, n);
    }
};