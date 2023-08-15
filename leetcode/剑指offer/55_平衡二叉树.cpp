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
private:
    bool res = true;
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }
    int dfs(TreeNode* root)
    {
        if(root == NULL) return 0;

        int leftCount = dfs(root->left);
        if(leftCount == -1) return -1;
        int rightCount =dfs(root->right);
        if(rightCount == -1) return -1;
        if(leftCount - rightCount > 1 || leftCount - rightCount < - 1)
        {
            return -1;
        }
        return std::max(leftCount, rightCount) + 1;
    }
};