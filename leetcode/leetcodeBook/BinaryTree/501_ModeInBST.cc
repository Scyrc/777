//
// Created by sc on 2023/8/31.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> res;
    int preValue = INT_MIN;
    int maxCount = 0;
    int count = 0;

    void helper(TreeNode* curr)
    {
        if(curr == nullptr) return;
        helper(curr->left);
        update(curr->val);
        helper(curr->right);
    }

    void update(const int& currValue)
    {
        if(currValue == preValue)
        {
            ++count;
        }
        else
        {
            preValue = currValue;
            count = 1;
        }

        if(count == maxCount)
        {
            res.push_back(preValue);
        }
        else if(count > maxCount)
        {
            maxCount = count;
            res = {currValue};
        }

    }
    vector<int> findMode(TreeNode* root) {
        helper(root);
        return res;
    }
};