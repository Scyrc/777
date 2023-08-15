//
// Created by sc on 2023/3/21.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (true)
        {
            if(slow == NULL || slow->next == NULL || fast->next  == NULL || fast->next->next  == NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};