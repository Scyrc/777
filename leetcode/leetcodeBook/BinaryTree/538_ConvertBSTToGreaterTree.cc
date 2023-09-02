//
// Created by sc on 2023/9/2.
//
#include <vector>
using namespace std;
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
    void helper(TreeNode* root, int& acc)
    {
        if(root->right != nullptr)
        {
            helper(root->right, acc);
        }
        root->val += acc;
        acc = root->val;

        if(root->left != nullptr)
            helper(root->left, acc);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return root;
        int tmp = 0;
        helper(root,tmp);
        return root;
    }
};