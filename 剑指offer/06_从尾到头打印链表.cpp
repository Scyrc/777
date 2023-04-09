//
// Created by sc on 2023/4/9.
//
#include <iostream>
#include <vector>
using std::vector;
//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int>& res;
    vector<int> reversePrint(ListNode* head) {
        fillVector(head);
        return res;
    }
    void fillVector(ListNode* node)
    {
        if(node == NULL) return;
        fillVector(node->next);
        res.push_back(node->val);
    }
};