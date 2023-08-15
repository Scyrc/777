//
// Created by sc on 2023/3/26.
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode* mid = GetMid(head);
        ListNode* start = ReverseList(mid->next);

        ListNode* p1 = head;
        ListNode* p2 = start;
        bool result = true;
        while (result && p2)
        {
            if(p1->val != p2->val) result = false;
            p1 = p1->next;
            p2 = p2->next;
        }

        mid->next = ReverseList(start);
        return result;
    }

    ListNode* GetMid(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = fast;
        while (fast->next && fast->next->next)
        {
            fast= fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* ReverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }
};