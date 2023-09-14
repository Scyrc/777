//
// Created by sc on 2023/9/13.
//

#include <vector>
#include <iostream>
using namespace std;
void help(vector<int>& arr, int low, int high)
{
    if(low >= high) return;
    int l = low;
    int r = high;
    int selectElem = arr[l];
    while (l != r)
    {
        while (l < r && arr[r] >= selectElem)
        {
            --r;
        }

        while ( l < r && arr[l] <= selectElem)
        {
            ++l;
        }

        if(l < r)
        {
            std::swap(arr[l], arr[r]);
        }
    }
    arr[low] = arr[l];
    arr[l] = selectElem;


    help(arr, low,  l - 1);
    help(arr,  l + 1,  high);
}
void quickSort(vector<int>& arr)
{
   help(arr, 0, arr.size()-1);
}
int main()
{
    vector<int> v {5, 4 ,3, 2 ,1};
    quickSort(v);
    for(auto& e : v)
    {
        cout<< e << " ";
    }
}