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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 1;
        queue<pair<TreeNode*, int>> cacheQueue;
        cacheQueue.push(pair<TreeNode*, int>(root, 1));
        while (!cacheQueue.empty())
        {
            auto x = cacheQueue.front();
            cacheQueue.pop();
            if(x.second > res) res = x.second;
            if(x.first->left) cacheQueue.push(pair<TreeNode*, int>(x.first->left, x.second+1));
            if(x.first->right) cacheQueue.push(pair<TreeNode*, int>(x.first->right, x.second+1));
        }
        return res;
    }
};