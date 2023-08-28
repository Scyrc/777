//
// Created by sc on 2023/8/28.
//

#include <string>
#include <vector>
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
private:
    vector<string> allPaths;
public:
    void fillPaths(TreeNode* node,  string path)
    {
        if(node == nullptr )
        {
            return;
        }

        path += "->";
        path += to_string(node->val);

        if(node->left && node->right)
        {
            fillPaths(node->left, path);
            fillPaths(node->right, path);
        }

        else if(node->left)
        {
            fillPaths(node->left, path);
        }

        else if(node->right)
        {
            fillPaths(node->right, path);
        }
        else
        {
            allPaths.push_back(path);
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return allPaths;
        string path = to_string(root->val);
        if(!root->left && !root->right)
        {
            allPaths.push_back(path);
            return allPaths;
        }

        fillPaths(root->left, path);
        fillPaths(root->right, path);

        return allPaths;
    }
};