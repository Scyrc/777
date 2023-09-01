//
// Created by sc on 2023/9/1.
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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(root == nullptr) return root;
        if(root->val == key)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if(root->left == nullptr)
            {
                auto tmp = root->right;
                delete root;
                return tmp;
            }
            else if(root->right == nullptr)
            {
                auto tmp = root->left;
                delete root;
                return tmp;
            }
            else
            {
                auto cur = root->right;
                while (cur->left != nullptr)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                auto tmp = root->right;
                delete root;
                return tmp;
            }
        }

        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};