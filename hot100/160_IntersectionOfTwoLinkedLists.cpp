//
// Created by sc on 2023/3/23.
//

// Definition for singly-linked list.
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto A = headA;
        auto B = headB;
        while (A!=B)
        {
            A = A!= nullptr ? A->next : headB;
            B = B!= nullptr ? B->next : headA;
        }
        return A;
    }
};
