//
// Created by sc on 2023/4/22.
//

#define NULL 0

//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

class Solution {
private:
    int count = 0;
    int target;
    int res;
public:
    int kthLargest(TreeNode* root, int k) {
        target = k;
        dfs(root);
        return res;
    }

    bool dfs(TreeNode* node)
    {
        if(node == NULL) return false;
        if(dfs(node->right)) return true;
        if(++count == target)
        {
            res = node->val;
            return true;
        }
        return dfs(node->left);
    }
};