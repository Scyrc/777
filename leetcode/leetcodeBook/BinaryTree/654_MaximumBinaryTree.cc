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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        int maxIndex = 0;
        int maxValue = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > maxValue)
            {
                maxValue = nums[i];
                maxIndex = i;
            }
        }

        TreeNode* root = new TreeNode(maxValue);

        if(maxIndex > 0)
        {
            vector<int> leftNums =  vector<int>(nums.begin(), nums.begin() + maxIndex);
            root->left = constructMaximumBinaryTree(leftNums);
        }

        if(maxIndex < nums.size() - 1)
        {
            vector<int> rightNums =  vector<int>(nums.begin() + maxIndex + 1, nums.end());
            root->right = constructMaximumBinaryTree(rightNums);
        }

        return root;
    }
};