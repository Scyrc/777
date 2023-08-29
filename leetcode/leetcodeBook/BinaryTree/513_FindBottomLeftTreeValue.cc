//
// Created by sc on 2023/8/29.
//

#include <queue>
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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return root->val;

        int res = root->val;

        queue<TreeNode*> cacheQueue;

        cacheQueue.push(root);
        while (!cacheQueue.empty())
        {
            res = cacheQueue.front()->val;
            int size = cacheQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = cacheQueue.front();
                cacheQueue.pop();
                if(node->left != nullptr)
                    cacheQueue.push(node->left);
                if(node->right != nullptr)
                    cacheQueue.push(node->right);
            }
        }
        return res;
    }
};