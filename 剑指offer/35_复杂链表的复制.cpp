//
// Created by sc on 2023/4/15.
//


#include <iostream>
#include <unordered_map>
using std::unordered_map;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> cacheMap;

        Node* cur = head;
        while (cur)
        {
            cacheMap[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur)
        {
            cacheMap[cur]->next = cacheMap[cur->next];
            cacheMap[cur]->random = cacheMap[cur->random];
            cur = cur->next;
        }
        return cacheMap[head];
    }
};