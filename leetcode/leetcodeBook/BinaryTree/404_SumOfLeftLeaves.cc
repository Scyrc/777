//
// Created by sc on 2023/8/29.
//

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
    void countLeftLeaves(TreeNode* node, int& count)
    {
        if(node == nullptr) return;

        if(node->left != nullptr && isLeaves(node->left)) count += node->left->val;

        if(node->left != nullptr)
            countLeftLeaves(node->left, count);

        if(node->right != nullptr)
            countLeftLeaves(node->right, count);
    }

    inline bool isLeaves(TreeNode* node)
    {
        return node->left == nullptr && node->right == nullptr;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0;

        int res = 0;

        countLeftLeaves(root, res);

        return res;
    }
};