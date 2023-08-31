//
// Created by sc on 2023/8/31.
//


using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <iostream>
class Solution {
public:
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    void help(TreeNode* root)
    {
        if(root == nullptr) return;

        help(root->left);
        if(pre != nullptr)
            res = min(res, std::abs(root->val - pre->val));

        pre = root;
        help(root->right);

    }
    int getMinimumDifference(TreeNode* root) {

        help(root);
        return res;
    }
};