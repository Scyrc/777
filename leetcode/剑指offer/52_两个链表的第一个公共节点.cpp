//
// Created by sc on 2023/4/20.
//

#define NULL 0

//Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* Node1 = headA;
        ListNode* Node2= headB;
        while (Node1 != Node2)
        {
            Node1 = Node1 != NULL ? Node1->next : headB;
            Node2 = Node2 != NULL ? Node2->next : headA;
        }
        return Node1;
    }
};