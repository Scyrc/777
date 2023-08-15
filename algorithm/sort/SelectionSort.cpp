//
// Created by sc on 2023/5/4.
//


#include <iostream>
#include <vector>
using std::vector;

void selectSort(vector<int>&& arr)
{
    int n = arr.size();
    int minIndex = 0;
    for (int i = 0; i < n-1; ++i)
    {
        minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if(arr[j] < arr[minIndex]) minIndex = j;

        if(minIndex != i) std::swap(arr[i], arr[minIndex]);
    }

    for(auto&& x : arr)
    {
        std::cout<< x <<",";
    }
    std::cout<<std::endl;
}

int main ()
{
    selectSort(vector<int>{1,2,3,4,5});
    selectSort(vector<int>{1,3,2,4,5});
    selectSort(vector<int>{5,4,3,2,1});
    selectSort(vector<int>{1,5,2,4,3});
}