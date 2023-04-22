//
// Created by sc on 2023/4/22.
//
#define NULL 0
#include <iostream>
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {

        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int count)
    {
        if(root == NULL) return count;
        ++count;
        return std::max(dfs(root->left, count), dfs(root->right, count));
    }
};