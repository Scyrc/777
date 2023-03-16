//
// Created by sc on 2023/3/16.
//

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
    void flatten(TreeNode* root) {
        while (root != nullptr)
        {
            if(root->left == nullptr)
            {
                root = root->right;
            }
            else
            {
                auto pre = root->left;
                while (pre->right)
                {
                    pre = pre->right;
                }
                pre->right= root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};