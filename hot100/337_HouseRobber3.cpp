//
// Created by sc on 2023/3/31.
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
    int rob(TreeNode* root) {
        pair<int, int> value = dfs(root);
        return max(value.first, value.second);
    }

    pair<int, int>  dfs(TreeNode* node)
    {
        pair<int, int> value = make_pair(0, 0);
        if(node == nullptr) return value;

        pair<int, int> valueLeft = dfs(node->left);
        pair<int, int> valueRight = dfs(node->right);

        value.first = max(valueLeft.first, valueLeft.second) + max(valueRight.first, valueRight.second);
        value.second = valueLeft.first + valueRight.first + node->val;

        return value;
    }
};