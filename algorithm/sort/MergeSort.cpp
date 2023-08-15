//
// Created by sc on 2023/5/4.
//

#include <iostream>
#include <vector>
using std::vector;

void merge(vector<int>& arr, int l, int r, int mid)
{
    int leftSize = mid - l + 1;
    int rightSize = r - mid;

    vector<int> left(arr.begin() + l, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + r + 1);

    int i =0, j = 0, k = l;

    while (i<leftSize && j<rightSize) arr[k++] = left[i] < right[j] ? left[i++] : right[j++];
    while (i<leftSize ) arr[k++] = left[i++];
    while (j<rightSize ) arr[k++] = right[j++];
}
void mergeSort(vector<int>&arr, int l, int r)
{
    if(l == r) return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l , r, mid);
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
    mergeSort(v1,0, v1.size() - 1);
    print(v1);

    vector<int> v2{1,3,2,4,5};
    mergeSort(v2,0, v2.size() - 1);
    print(v2);

    vector<int> v3{5,4,3,2,1};
    mergeSort(v3,0, v3.size() - 1);
    print(v3);

    vector<int> v4{1,5,2,4,3};
    mergeSort(v4,0, v4.size() - 1);
    print(v4);

}