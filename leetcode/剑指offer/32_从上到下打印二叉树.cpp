//
// Created by sc on 2023/4/14.
//


#include <iostream>
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


#include <vector>
using std::vector;
#include <queue>
using std::queue;

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if(root == NULL) return vector<int>();
        queue<TreeNode*> cacheQueue;
        vector<int> res;
        TreeNode* node = nullptr;
        cacheQueue.push(root);
        while (!cacheQueue.empty())
        {
            node = cacheQueue.front();
            cacheQueue.pop();
            res.push_back(node->val);
            if(node->left) cacheQueue.push(node->left);
            if(node->right) cacheQueue.push(node->right);
        }
        return res;
    }
};