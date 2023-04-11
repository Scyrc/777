//
// Created by sc on 2023/4/10.
//

#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) return head->next;
        ListNode dummyNode = ListNode(-1);
        ListNode* prev = &dummyNode;
        ListNode* cur = head;
        while (cur && cur->val!=val)
        {
            prev = cur;
            cur = cur->next;
        }
        if(cur)
        {
            prev->next = cur->next;
        }
        return head;
    }
};