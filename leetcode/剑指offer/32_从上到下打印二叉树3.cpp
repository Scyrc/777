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
#include <algorithm>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return vector<vector<int>>();
        vector<vector<int>> res;
        bool flag = false;
        queue<TreeNode*> cacheQueue;
        cacheQueue.push(root);
        TreeNode* node = nullptr;
        while (!cacheQueue.empty())
        {
            vector<int> tmp;
            int i = cacheQueue.size();
            while (i-- > 0) {
                node = cacheQueue.front();
                cacheQueue.pop();
                tmp.push_back(node->val);

                if(node->left) cacheQueue.push(node->left);
                if(node->right) cacheQueue.push(node->right);
            }
            if(flag)
            {
                std::reverse(tmp.begin(), tmp.end());
            }
            flag = !flag;
            res.push_back(tmp);
        }
        return res;
    }
};