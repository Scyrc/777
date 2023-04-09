//
// Created by sc on 2023/4/9.
//
#include <iostream>
#include <vector>

using std::vector;
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if(preorder.size() == 0 && inorder.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 0; i < inorder.size(); ++i) {
            if(inorder[i] == preorder[0]) // root node in inorder
            {
                if(i!=0)
                {
                    root->left = buildTree(vector<int>(preorder.begin()+1,  preorder.begin() + i +1), vector<int>(inorder.begin(), inorder.begin() + i));
                }
                if(i!=preorder.size()-1)
                {
                    root->right = buildTree(vector<int>(preorder.begin() + i+ 1, preorder.end()), vector<int>(inorder.begin() + i + 1, inorder.end()));
                }
                break;
            }
        }
        return root;
    }
};