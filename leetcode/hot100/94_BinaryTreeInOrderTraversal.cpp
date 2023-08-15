//
// Created by sc on 2023/3/13.
//
#include <vector>
#include <iostream>
using namespace std;

#include <stack>

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
    void goAlongLeftBranch(TreeNode* node, stack<TreeNode*>& CacheStack)
    {
        while (node)
        {
            CacheStack.push(node);
            node = node->left;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> CacheStack;

        while (true)
        {
            goAlongLeftBranch(root, CacheStack);
            if(CacheStack.empty()) return res;
            root = CacheStack.top();
            res.push_back(root->val);
            CacheStack.pop();
            root = root->right;
        }
    }

    vector<int> inorderTraversalRecursive(TreeNode* root) {
        vector<int> res;
        Recursive(root, res);
        return res;
    }

    void Recursive(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;
        Recursive(root->left, res);
        res.push_back(root->val);
        Recursive(root->right, res);
    }

};