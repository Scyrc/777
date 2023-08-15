//
// Created by sc on 2023/5/4.
//


#include <iostream>
#include <vector>
using std::vector;

void shellSort(vector<int> arr)
{
    int n = arr.size();

    int i, j , gap, temp;

    for(gap = n / 2; gap > 0; gap/=2)
    {
        for (i = gap; i< n; ++i)
        {
            temp = arr[i];
            for (j = i - gap; j>=0 && temp < arr[j]; j-=gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }

    for(auto&& x : arr)
    {
        std::cout<< x <<",";
    }
    std::cout<<std::endl;
}

int main ()
{
    shellSort(vector<int>{1,2,3,4,5});
    shellSort(vector<int>{1,3,2,4,5});
    shellSort(vector<int>{5,4,3,2,1});
    shellSort(vector<int>{1,5,2,4,3});
}