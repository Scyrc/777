//
// Created by sc on 2023/5/4.
//
#include <iostream>
#include <vector>
using std::vector;

void bubbleSort(vector<int>&&arr)
{
    int n = arr.size();
    bool flag = false;

    for (int i = 0; i < n - 1; ++i)
    {
        flag = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(!flag) break;
    }

    for(auto&& x : arr)
    {
        std::cout<< x <<",";
    }
    std::cout<<std::endl;
}

int main ()
{
    bubbleSort(vector<int>{1,2,3,4,5});
    bubbleSort(vector<int>{1,3,2,4,5});
    bubbleSort(vector<int>{5,4,3,2,1});
    bubbleSort(vector<int>{1,5,2,4,3});
}