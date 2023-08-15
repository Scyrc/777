//
// Created by sc on 2023/5/25.
//
#include <iostream>
#include <vector>
#include <algorithm>

int add(auto x, auto y)
{
    return x + y;
}
void test_auto()
{
    auto x = 1;
    auto y = 2;
    std::cout<<add(x, y);
}

void test_decltype()
{
    auto x = 1;
    auto y = 2;
    decltype(x+y) z;

    if(std::is_same<decltype(x), int>::value)
        std::cout << "type x == int" << std::endl;

    if (std::is_same<decltype(x), float>::value)
        std::cout << "type x == float" << std::endl;

    if (std::is_same<decltype(x), decltype(z)>::value)
        std::cout << "type z == type x" << std::endl;
}

int main()
{
    //test_auto();
    test_decltype();
}