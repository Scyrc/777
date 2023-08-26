//
// Created by sc on 2023/8/26.
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
    void calculateDepth(TreeNode* root, int& depth)
    {
        if(root == nullptr) return;

        int depthL = depth + 1;

        int depthR = depth + 1;

        if(root->left != nullptr) calculateDepth(root->left, depthL);
        if(root->right != nullptr) calculateDepth(root->right, depthR);

        depth = depthL > depthR ? depthL : depthR;
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;
        calculateDepth(root, depth);
        return depth;
    }
};