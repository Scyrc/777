//
// Created by sc on 2023/3/14.
//
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<pair<TreeNode*, int>> cacheQueue;
        cacheQueue.push(pair<TreeNode*, int>(root, 0));
        while (!cacheQueue.empty())
        {
            auto x = cacheQueue.front();
            cacheQueue.pop();
            if(res.size()>x.second)
            {
                res[x.second].push_back(x.first->val);
            }
            else
            {
                res.push_back(vector<int>());
                res[x.second].push_back(x.first->val);
            }
            if(x.first->left) cacheQueue.push(pair<TreeNode*, int>(x.first->left, x.second+1));
            if(x.first->right) cacheQueue.push(pair<TreeNode*, int>(x.first->right, x.second+1));
        }
        return res;
    }
};