//
// Created by sc on 2023/4/16.
//

#include <vector>
#include <iostream>

using std::vector;
class Solution {
public:
    int target;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k>= arr.size()) return arr;
        target = k;
        return quickSelect(arr, 0, arr.size()-1);
    }

    vector<int> quickSelect(vector<int>& arr, int l, int r)
    {
        int i = l ,j = r;

        while (i < j)
        {
            while (i < j && arr[j]>=arr[l]) --j;
            while (i < j && arr[i]<=arr[l]) ++i;
            std::swap(arr[i], arr[j]);
        }

        std::swap(arr[i], arr[l]);

        if(i > target) return quickSelect(arr, l, i-1);
        if(i < target) return quickSelect(arr, i+1, r);

        return vector<int>(arr.begin(), arr.begin() + target);
    }
};