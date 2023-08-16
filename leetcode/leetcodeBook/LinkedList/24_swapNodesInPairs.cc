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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        auto prev = new ListNode(-1);
        auto res = prev;
        auto slow = head;
        auto fast = head->next;
        while (slow && slow->next)
        {
            fast = slow->next;
            prev->next = fast;
            slow->next = fast->next;
            fast->next = slow;
            prev = slow;
            slow = slow->next;
        }

        return res->next;
    }
};