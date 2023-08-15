//
// Created by sc on 2023/2/27.
//

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* Head = new ListNode();
        ListNode* currNode = Head;
        while (list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                currNode->next = new ListNode(list1->val);
                currNode = currNode->next;
                list1 = list1->next;
                continue;
            }
            else
            {
                currNode->next = new ListNode(list2->val);
                currNode = currNode->next;
                list2 = list2->next;
            }
        }

        currNode->next = list1? list1 : list2;
        return Head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return Merge(lists, 0, lists.size()-1);
    }

    ListNode* Merge(vector<ListNode*>& lists, int l, int r)
    {
        if(l == r) return lists[l];
        if(l > r) return nullptr;

        int mid = (l + r) / 2;

        return mergeTwoLists(Merge(lists, l, mid), Merge(lists, mid+1, r) );
    }
};