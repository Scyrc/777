//
// Created by sc on 2023/3/15.
//


#include <vector>
#include <queue>
#include <iostream>
using namespace std;

//Definition for a binary tree node.
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
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if(preorder.size() == 0 && inorder.size()==0) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        for(int i=0;i<inorder.size();++i)
        {
            if(preorder[0] == inorder[i])
            {
                vector<int>::const_iterator preStart = preorder.begin();
                vector<int>::const_iterator preMid = preorder.begin() + i;
                auto inStart = inorder.begin();
                auto inMid = inorder.begin() + i;


                if(i!=0)
                {
                    root->left = buildTree(vector<int>(preStart+1, preMid+1), vector<int>(inStart, inMid));
                }



                if(i !=preorder.size()-1)
                {
                    root->right = buildTree(vector<int>(preMid+1, preorder.end()), vector<int>(inMid+1, inorder.end()));
                }

                break;
            }
        }

        return root;
    }
};

int main()
{
    vector<int> a {3,9,20,15,7};
    vector<int> b {9,3,15,20,7};
    auto t1 = a.begin() +1;
    auto t2 = a.begin() +3;
    vector<int> c(t1, t2);

    Solution S;
    auto t = S.buildTree(a, b);
    std::cout<<t->val;
}