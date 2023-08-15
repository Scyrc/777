//
// Created by sc on 2023/5/25.
//
#include <iostream>
#include <vector>
#include <algorithm>
void if_switch()
{
    std::vector<int> vec {1, 2, 3};

    // C++ 17 前
    //const std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 2);

    // C++ 17 之后
    if(const std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 2);it != vec.end())
    {
        *it = 10;
    }
}


int main()
{
    if_switch();
}