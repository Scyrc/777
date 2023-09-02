//
// Created by sc on 2023/9/2.
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
    TreeNode* helper(vector<int>& nums, const int& left, const int& right)
    {
        int mid = (left + right) / 2;

        auto root = new TreeNode(nums[mid]);;
        if(left > right) return nullptr;

        if(left == right) return root;


        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return helper(nums, 0, nums.size()- 1);
    }
};