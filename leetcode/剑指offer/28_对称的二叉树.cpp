//
// Created by sc on 2023/4/13.
//

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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;

        return (left->val == right->val) && dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};