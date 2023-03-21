//
// Created by sc on 2023/3/21.
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
    ListNode* sortList(ListNode* head) {
        ListNode helperHead(0);
        helperHead.next = head;
        auto p = head;
        int len = 0;
        while (p)
        {
            ++len;
            p = p->next;
        }

        for(int size = 1; size < len; size*=2)
        {
            auto cur = helperHead.next;
            auto tail = &helperHead;

            while (cur)
            {
                auto left = cur;
                auto right = cut(left, size);
                cur = cut(right, size);

                tail->next = merge(left, right);
                while (tail->next)
                {
                    tail = tail->next;
                }
            }
        }

        return helperHead.next;
    }

    ListNode* cut(ListNode* head, int size)
    {
        ListNode* p = head;
        while (--size && p)
        {
            p = p->next;
        }
        if(p== nullptr) return nullptr;

        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* Head = new ListNode();
        ListNode* currNode = Head;
        while (list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                currNode->next = list1;
                currNode = currNode->next;
                list1 = list1->next;
            }
            else
            {
                currNode->next = list2;
                currNode = currNode->next;
                list2 = list2->next;
            }
        }

        currNode->next = list1? list1 : list2;
        return Head->next;
    }
};