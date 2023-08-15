//
// Created by sc on 2023/2/27.
//



// Definition for singly-linked list.
  struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = new ListNode();
        pre->next = head;
        ListNode* start = pre;
        ListNode* end = pre;

        while (n!=0)
        {
            start = start->next;
            n--;
        }

        while (start->next != nullptr)
        {
            start = start->next;
            end = end->next;
        }

        end->next = end->next->next;
        return pre->next;
    }
};