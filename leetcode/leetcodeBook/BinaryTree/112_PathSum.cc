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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        int count = 0;
        return findPath(root, count, targetSum);
    }

protected:
    bool findPath(TreeNode* node, int& currentSum, const int& targetSum)
    {
        if(node->left == nullptr && node->right == nullptr)
            return currentSum + node->val == targetSum;

        if(node->left != nullptr)
        {
            currentSum += node->val;
            if(findPath(node->left, currentSum, targetSum))
            {
                currentSum -= node->val;
                return true;
            }
            else
            {
                currentSum -= node->val;
            }
        }

        if(node->right != nullptr)
        {
            currentSum += node->val;
            bool res = findPath(node->right, currentSum, targetSum);
            currentSum -= node->val;
            return res;
        }

        return false;
    }
};

