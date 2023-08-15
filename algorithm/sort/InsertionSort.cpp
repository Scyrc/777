//
// Created by sc on 2023/5/4.
//

#include <iostream>
#include <vector>
using std::vector;

void insertSort(vector<int> arr)
{
    int n = arr.size();
    int i, j, temp;
    for (i = 1; i < n; ++i)
    {
        temp = arr[i];

        for (j = i; j > 0 && arr[j - 1] > temp; --j)
            arr[j] = arr[j - 1];

        arr[j] = temp;
    }

    for(auto&& x : arr)
    {
        std::cout<< x <<",";
    }
    std::cout<<std::endl;
}
int main ()
{
    insertSort(vector<int>{1,2,3,4,5});
    insertSort(vector<int>{1,3,2,4,5});
    insertSort(vector<int>{5,4,3,2,1});
    insertSort(vector<int>{1,5,2,4,3});
}