//
// Created by sc on 2023/4/17.
//

#include <string>

using std::string;
class Solution {
public:
    int translateNum(int num) {
        string numStr = std::to_string(num);
        int a = 1, b = 1;

        for (int i = 2; i <=numStr.size(); ++i) {
            string tmp = numStr.substr(i-2, 2);
            int c = tmp.compare("10") >=0 && tmp.compare("25") <= 0 ?  a + b : a;
            b = a;
            a = c;
        }

        return a;
    }
};