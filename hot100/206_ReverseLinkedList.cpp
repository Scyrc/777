//
// Created by sc on 2023/3/23.
//

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur)
        {
            auto * t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        return prev;
    }
};
