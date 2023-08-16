//
// Created by sc on 2023/8/16.
//
#include <stdio.h>
#include <iostream>
using namespace  std;

class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    MyLinkedList() {
        listSize = 0;
        dummyHead = new ListNode(-1);
    }

    int get(int index) {
        if(index >= listSize || index < 0) return -1;
        auto cur = dummyHead->next;
        while (index-- > 0)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ++listSize;
        auto node = new ListNode(val);
        node->next = dummyHead->next;
        dummyHead->next = node;
    }

    void addAtTail(int val) {
        auto cur = dummyHead;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        ++listSize;
        cur->next = new ListNode(val);
    }

    void addAtIndex(int index, int val) {
        if(index > listSize || index < 0) return;
        auto cur = dummyHead;
        while (index-- > 0)
        {
            cur = cur->next;
        }

        ++listSize;
        auto node = new ListNode(val);
        if(cur->next != nullptr)
            node->next = cur->next;
        cur->next = node;
    }

    void deleteAtIndex(int index) {
        if(index >= listSize || index < 0) return;
        auto cur = dummyHead->next;
        auto prev = dummyHead;
        while (index-- > 0)
        {
            prev = cur;
            cur = cur->next;
        }

        --listSize;
        auto deleteNode = cur;
        prev->next = cur->next;

        delete deleteNode;
    }
private:
    size_t listSize;
    ListNode* dummyHead;
};

int main()
{
    MyLinkedList* obj = new MyLinkedList();
    /*obj->addAtIndex(0,10);
    obj->addAtIndex(0,20);
    obj->addAtIndex(1,30);*/

    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    int param_1 = obj->get(1);
    std::cout<< param_1<<std::endl;

    obj->deleteAtIndex(1);
    param_1 = obj->get(1);

    std::cout<< param_1;

}



