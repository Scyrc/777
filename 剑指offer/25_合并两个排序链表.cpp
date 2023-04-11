//
// Created by sc on 2023/4/11.
//

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyHead = ListNode(-1);
        ListNode* head = &dummyHead;

        while (l1 && l2)
        {
            if(l1->val < l2->val)
            {
                head->next = l1;
                head = l1;
                l1 = l1->next;
            }
            else
            {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
        }
        while (l1)
        {
            head->next = l1;
            head = l1;
            l1 = l1->next;
        }
        while (l2)
        {
            head->next = l2;
            head = l2;
            l2 = l2->next;
        }
        return dummyHead.next;
    }
};