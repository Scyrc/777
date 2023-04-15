//
// Created by sc on 2023/4/15.
//

#include <string>
#include <vector>
using std::string;
using std::vector;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return std::to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    void split(const std::string& s, std::vector<std::string>& tokens, char delim = ' ') {
        tokens.clear();
        size_t lastPos = s.find_first_not_of(delim, 0);
        size_t pos = s.find(delim, lastPos);
        while (lastPos != std::string::npos) {
            tokens.emplace_back(s.substr(lastPos, pos - lastPos));
            lastPos = s.find_first_not_of(delim, pos);
            pos = s.find(delim, lastPos);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        split(data, tokens, ',');
        int index = -1;
        return buildTree(tokens, index);
    }

    TreeNode* buildTree(vector<string>& tokens, int& i)
    {
        ++i;
        if(i == tokens.size()) return nullptr;
        string rootVal = tokens[i];
        if(rootVal == "#") return nullptr;
        TreeNode* node = new TreeNode(std::stoi(rootVal));
        node->left = buildTree(tokens, i);
        node->right = buildTree(tokens, i);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));8