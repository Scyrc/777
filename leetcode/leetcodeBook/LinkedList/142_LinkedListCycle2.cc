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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (true)
        {
            if(fast == NULL || fast->next == NULL) return NULL;

            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }

        slow = head;

        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};