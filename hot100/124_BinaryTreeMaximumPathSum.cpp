//
// Created by sc on 2023/3/16.
//

#include <iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int res = INT_MIN;

    int dfs(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int innerMaxSum = left + root->val + right;
        res = max(res, innerMaxSum);
        int outputMaxSum = root->val + max(left, right);
        return max(outputMaxSum, 0);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};