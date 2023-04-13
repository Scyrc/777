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
    TreeNode* mirrorTree(TreeNode* root) {
        swapNode(root);
        return root;
    }
    void swapNode(TreeNode* root)
    {
        if(root == nullptr) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        swapNode(root->left);
        swapNode(root->right);
    }
};