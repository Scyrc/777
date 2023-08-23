//
// Created by sc on 2023/8/23.
//
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int lenA = 0, lenB = 0;
        while (p1 != NULL)
        {
            ++lenA;
            p1 = p1->next;
        }

        while (p2 != NULL)
        {
            ++lenB;
            p2 = p2->next;
        }

        p1 = headA;
        p2 = headB;

        if(lenB > lenA)
        {
            std::swap(lenA, lenB);
            std::swap(p1, p2);
        }

        int gap = lenA - lenB;

        while (gap--)
        {
            p1 = p1->next;
        }

        while (p1 != NULL)
        {
            if(p1 == p2)
                return p1;

            p1 = p1->next;
            p2 = p2->next;
        }

        return NULL;
    }
};
