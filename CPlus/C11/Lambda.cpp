//
// Created by sc on 2023/4/23.
//
#include <iostream>
void Lambda_value_capture()
{
    int value = 1;
    auto copy_value = [value]
    {
        return value;
    };

    auto copy_value1 = [value] ()-> int
    {
        return value;
    };

    value = 100;
    std::cout<<copy_value()<<std::endl;
    std::cout<<copy_value1()<<std::endl;

}

void Lambda_reference_capture()
{
    int value = 1;
    auto copy_value = [&value]
    {
        return value;
    };

    value = 100;
    std::cout<<copy_value()<<std::endl;
}

void Lambda_implicit_capture()
{
    int value = 1;
    int value1 = 2;
    auto copy_value_1 = [&](int t)
    {
        return value + value1 + t;
    };
    std::cout<<"sizeof"<<sizeof(copy_value_1)<<std::endl;
    auto copy_value_2 = [=]
    {
        return value;
    };
    std::cout<<"sizeof"<<sizeof(copy_value_2)<<std::endl;

    value = 100;
    std::cout<<copy_value_1(1)<<std::endl;  // 100
    std::cout<<copy_value_2()<<std::endl;  // 1
}

int main()
{
//    Lambda_value_capture();
//    Lambda_reference_capture();
    Lambda_implicit_capture();

    auto add = [] (auto x, auto y)
    {
        return x + y;
    };

    std::cout<< add(1, 5)<<std::endl;
    std::cout<< add(2, 5)<<std::endl;
    std::cout<< add(2.3, 5.2)<<std::endl;
}