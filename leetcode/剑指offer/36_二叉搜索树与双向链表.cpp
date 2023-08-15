//
// Created by sc on 2023/4/15.
//
#include <vector>
using std::vector;
#define NULL 0
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL ) return NULL;
        if(root->left == NULL && root->right == NULL)
        {
            root->left = root;
            root->right = root;
            return root;
        }
        vector<Node*> cacheVector;
        MidSequence(root, cacheVector);

        for (int i = 1; i < cacheVector.size() -1; ++i)
        {
            cacheVector[i]->left = cacheVector[i-1];
            cacheVector[i]->right = cacheVector[i+1];
        }
        cacheVector[0]->left = cacheVector[cacheVector.size()-1];
        cacheVector[0]->right = cacheVector[1];

        cacheVector[cacheVector.size()-1]->left = cacheVector[cacheVector.size()-2];
        cacheVector[cacheVector.size()-1]->right = cacheVector[0];

        return cacheVector[0];
    }

    void MidSequence(Node* node, vector<Node*>& cacheVector)
    {
        if(node == NULL) return;
        MidSequence(node->left, cacheVector);
        cacheVector.push_back(node);
        MidSequence(node->right, cacheVector);
    }
};