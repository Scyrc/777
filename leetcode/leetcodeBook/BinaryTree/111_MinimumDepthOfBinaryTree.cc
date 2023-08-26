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
    void calculateMinimumDepth(TreeNode* root, int& depth)
    {
        if(root == nullptr) return;



        if(root->left != nullptr && root->right == nullptr) calculateMinimumDepth(root->left, ++depth);
        else if(root->right != nullptr && root->left == nullptr) calculateMinimumDepth(root->right, ++depth);
        else
        {
            int depthL = depth + 1;
            int depthR = depth + 1;
            calculateMinimumDepth(root->left, depthL);
            calculateMinimumDepth(root->right, depthR); *
            depth = depthL > depthR ? depthR : depthL;
        }
    }
    int minDepth(TreeNode* root) {
        int depth = 0;
        calculateMinimumDepth(root, depth);
        return depth;
    }
};