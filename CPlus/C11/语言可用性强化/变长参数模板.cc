//
// Created by sc on 2023/5/25.
//

#include <iostream>
//void print()
//{
//
//}
template <typename T,typename... Arg>
void print(T firstArg, Arg... args)
{
    std::cout<< firstArg << std::endl;

    if constexpr (sizeof...(args) > 0)
    {
        print(args...);
    }
}

int main()
{
    print(1, "str", 3.14);
}