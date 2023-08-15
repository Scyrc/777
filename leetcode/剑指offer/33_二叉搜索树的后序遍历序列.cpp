//
// Created by sc on 2023/4/14.
//

#include <vector>
using std::vector;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty()) return true;
        if(postorder.size() == 1) return true;

        return verifyPostorderCore(postorder, 0, postorder.size()-1);
    }

    bool verifyPostorderCore(vector<int>& postorder, int start, int end)
    {
        if(start >= end) return true;

        int mid = start;
        while ((mid <= end) && postorder[mid] < postorder[end]) ++mid;

        for (int i = mid; i < end; ++i) {
            if(postorder[i] <= postorder[end]) return false;
        }

        return verifyPostorderCore(postorder, start, mid-1) && verifyPostorderCore(postorder, mid, end-1);
    }
};