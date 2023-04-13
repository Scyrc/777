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
    bool isSameTree(TreeNode* A, TreeNode* B)
    {
        if(B == NULL) return true;
        if(A == NULL) return false;

        if(A->val != B->val) return false;

        return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL) return false;

        if(isSameTree(A, B)) return true;

        return isSubStructure(A->left, B) || isSameTree(A->right, B);
    }
};