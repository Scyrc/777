//
// Created by sc on 2023/8/30.
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

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.size() == 0) return nullptr;

        int rootValue = preorder.front();
        TreeNode* root = new TreeNode(rootValue);

        if(preorder.size() == 1) return root;

        auto  rootIter = std::find(inorder.begin(), inorder.end(), rootValue);
        int rootIndex = rootIter - inorder.begin();

        auto leftPreOrder = vector<int>(preorder.begin() + 1, preorder.begin() + rootIndex);
        auto rightPreOrder = vector<int>(preorder.begin() + rootIndex, preorder.end());

        auto leftInOrder = vector<int>(inorder.begin(), rootIter);
        auto rightInOrder = vector<int>(rootIter + 1, inorder.end());


        root->left = helper(leftPreOrder, leftInOrder);
        root->right = helper(rightPreOrder, rightInOrder);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if(inorder.size() == 0) return nullptr;
        return helper(preorder, inorder);
    }
};