//
// Created by sc on 2023/12/20.
//

#include "string"
#include "iostream"
using namespace std;
void test(string s)
{
    int count = 0;
    char target = '0';
    for(const auto& elem : s)
    {
        if(elem != target)
        {
            ++count;
            target = (target == '0') ? '1' : '0';
        }
    }

    cout<<count<<endl;
}
int main()
{
    string s = "1011";
    test(s);
    s = "1011111";
    test(s);

    s = "000001";
    test(s);
}