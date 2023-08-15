//
// Created by sc on 2023/5/5.
//


#include <iostream>
#include <vector>
using std::vector;


void countSort(vector<int>&& arr) {
    int maxElement = arr[0], minElement = arr[0];
    int n = arr.size();
    int i = 0;

    for (i = 1; i < n; ++i) {
        maxElement = arr[i] > maxElement ? arr[i] : maxElement;
        minElement = arr[i] < minElement ? arr[i] : minElement;
    }

    int length = maxElement - minElement + 1;

    vector<int> helpArr(length);
    vector<int> targetArr(n);

    for (i = 0; i < n; ++i) helpArr[arr[i] - minElement]++;

    for (i = 1; i < length; ++i) helpArr[i] += helpArr[i - 1];

    for (i = 0; i < n; ++i) targetArr[--helpArr[arr[i] - minElement]] = arr[i];

    for(auto&& x : targetArr)
    {
        std::cout<< x <<",";
    }
    std::cout<<std::endl;
}

int main ()
{
    countSort(vector<int>{1,2,3,4,5, 7});
    countSort(vector<int>{9, 1,3,2,4,5});
    countSort(vector<int>{5,4,3,2,1});
    countSort(vector<int>{1,5,2,4,3});
}