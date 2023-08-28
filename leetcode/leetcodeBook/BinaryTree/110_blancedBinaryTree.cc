//
// Created by sc on 2023/8/28.
//

#include <math.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using namespace std;
class Solution {
public:
    int getHeight(TreeNode* node)
    {
        if(node == nullptr) return 0;

        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        if(! isBalanced(root->left))
            return false;

        if(! isBalanced(root->right))
            return false;
        return std::abs(getHeight(root->left) - getHeight(root->right)) < 2;
    }
};