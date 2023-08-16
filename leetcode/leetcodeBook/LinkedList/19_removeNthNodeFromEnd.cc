//
// Created by sc on 2023/8/16.
//
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = n;
        auto fast = head;
        while (--n > 0)
        {
            fast = fast->next;
        }
        auto dummyHead= new ListNode(-1);
        auto slow = dummyHead;
        slow->next = head;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummyHead->next;
    }
};