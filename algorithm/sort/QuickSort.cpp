//
// Created by sc on 2023/5/5.
//

#include <iostream>
#include <vector>
using std::vector;

void quickSort(vector<int>&arr, int left, int right)
{
    if(left >= right) return;
    int i = left, j = right, pivot;
    pivot = arr[left];

    while (i!=j)
    {
        while (arr[j] >= pivot && i<j) j--;

        while (arr[i] <= pivot && i<j) i++;

        if(i<j) std::swap(arr[i], arr[j]);
    }

    arr[left] = arr[i];
    arr[i] = pivot;

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
void print(vector<int>& arr)
{
    for(auto&& x : arr)
    {
        std::cout<< x <<",";
    }
    std::cout<<std::endl;
}
int main()
{
    vector<int> v1{1,2,3,4,5};
    quickSort(v1,0, v1.size() - 1);
    print(v1);

    vector<int> v2{1,3,2,4,5};
    quickSort(v2,0, v2.size() - 1);
    print(v2);

    vector<int> v3{5,4,3,2,1};
    quickSort(v3,0, v3.size() - 1);
    print(v3);

    vector<int> v4{1,5,2,4,3};
    quickSort(v4,0, v4.size() - 1);
    print(v4);
}
