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

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> CacheStack;
        long pre = LONG_MIN;
        while (true)
        {
            goAlongLeftBranch(root, CacheStack);
            if(CacheStack.empty()) return true;
            root = CacheStack.top();
            if(root->val <= pre) return false;
            pre = root->val;
            CacheStack.pop();
            root = root->right;
        }
    }
};