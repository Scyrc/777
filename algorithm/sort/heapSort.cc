//
// Created by sc on 2023/12/28.
//
#include <iostream>
#include <vector>
using std::vector;

#include<algorithm>
using namespace std;


void heapify(vector<int>& v, int n, int index)
{
    int maxIndex = index;

    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if(left < n && v[left] > v[maxIndex])
        maxIndex = left;

    if(right < n && v[right] > v[maxIndex])
        maxIndex = right;


    if(maxIndex != index)
    {
        swap(v[index], v[maxIndex]);
        heapify(v, n, maxIndex);
    }
}
void heapSort(vector<int>& v)
{
    for(int i=v.size()/2-1;i>=0;--i)
    {
        heapify(v, v.size(), i);
    }

    for (int i = v.size()-1; i >=1 ; --i) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


int main()
{
    vector<int> v{12, 11, 13, 5, 6 ,3};
    heapSort(v);


    for(auto& elem : v)
    {
        cout<< elem << " ";
    }
}