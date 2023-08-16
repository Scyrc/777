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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res  = new ListNode(0);
        ListNode* cur = res;

        while (head != nullptr)
        {
            if(head->val != val)
            {
                cur->next = head;
                cur = cur->next;
            }
            head = head->next;
        }

        cur->next = nullptr;
        return  res->next;
    }
};