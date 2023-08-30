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

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.size() == 0) return nullptr;

        int rootValue = postorder.back();
        TreeNode* root = new TreeNode(rootValue);

        if(postorder.size() == 1) return root;

        auto  rootIter = std::find(inorder.begin(), inorder.end(), rootValue);
        int rootIndex = rootIter - inorder.begin();
        auto leftInOrder = vector<int>(inorder.begin(), rootIter);
        auto rightInOrder = vector<int>(rootIter + 1, inorder.end());

        postorder.pop_back();

        auto leftPostOrder = vector<int>(postorder.begin(), postorder.begin() + rootIndex);
        auto rightPostOrder = vector<int>(postorder.begin() + rootIndex, postorder.end());

        root->left = helper(leftInOrder, leftPostOrder);
        root->right = helper(rightInOrder, rightPostOrder);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.size() == 0) return nullptr;
        return helper(inorder, postorder);
    }
};