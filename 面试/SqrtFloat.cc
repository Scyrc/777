//
// Created by sc on 2023/9/9.
//

#include <vector>
#include <iostream>
using namespace std;
float func(const float&  target)
{
    if(target == 1) return 1;
    float low;
    float high;
    if(target > 1)
    {
        low = 1;
        high = target;
    }
    else
    {
        low = 0;
        high = 1;
    }
    float  cur = (low + high) / 2.0f;
    float e = 0.000001;
    while (true)
    {
        cur = (low + high) / 2.0f;
        float currV = cur * cur;
        if(currV > target + e)
        {
            high = cur;
        }
        else if(currV < target - e)
        {
            low = cur;
        }
        else
        {
            return cur;
        }
    }
}

int main()
{
    float res= func(0.6);
    std :: cout << res << std::endl;
    std :: cout << res * res<< std::endl;;

    res= func(1);
    std :: cout << res << std::endl;
    std :: cout << res * res<< std::endl;;

    res= func(6);
    std :: cout << res << std::endl;
    std :: cout << res * res<< std::endl;;
}

