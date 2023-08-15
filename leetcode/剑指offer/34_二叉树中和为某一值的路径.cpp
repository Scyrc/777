//
// Created by sc on 2023/4/15.
//

#include <vector>
using std::vector;
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
    vector<vector<int>>  res;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> tmp;
        dfs(tmp, root, target);
        return res;
    }

    void dfs(vector<int>& cacheVector,TreeNode* node, int& target) {
        if(node == nullptr) return;
        target -= node->val;
        cacheVector.push_back(node->val);
        if(target == 0 && node->left == nullptr && node->right == nullptr)
        {
            res.push_back(cacheVector);
            target += node->val;
            cacheVector.pop_back();
            return;
        }
        dfs(cacheVector, node->left,target);
        dfs(cacheVector, node->right,target);
        target += node->val;
        cacheVector.pop_back();
    }
};