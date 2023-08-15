//
// Created by sc on 2023/3/21.
//

#include <unordered_map>
struct DoubleLinkedList
{
    int key;
    int value;
    DoubleLinkedList* pre;
    DoubleLinkedList* next;
    DoubleLinkedList() : key(0), value(0), pre(nullptr), next(nullptr) {}
    DoubleLinkedList(int _key, int _value): key(_key), value(_value), pre(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    std::unordered_map<int, DoubleLinkedList*> Cache;
    DoubleLinkedList* Head;
    DoubleLinkedList* Tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        Head = new DoubleLinkedList();
        Tail = new DoubleLinkedList();
        Head->next = Tail;
        Tail->pre = Head;
    }

    int get(int key) {
        if(Cache.count(key) == 0)
        {
           return -1;
        }

        DoubleLinkedList* node = Cache[key];
        MoveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if(Cache.count(key) == 0)
        {
            DoubleLinkedList* node = new DoubleLinkedList(key, value);
            Cache[key] = node;
            AddToHead(node);
            ++size;
            if(size > capacity)
            {
                DoubleLinkedList* nodeToRemoved = RemoveTail();
                Cache.erase(nodeToRemoved->key);
                delete nodeToRemoved;
                --size;
            }
        }
        else
        {
            DoubleLinkedList* node = Cache[key];
            node->value = value;
            MoveToHead(node);
        }
    }
    void RemoveNode(DoubleLinkedList* node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void MoveToHead(DoubleLinkedList* node)
    {
        RemoveNode(node);
        AddToHead(node);
    }
    void AddToHead(DoubleLinkedList* node)
    {
        node->pre = Head;
        node->next = Head->next;
        Head->next->pre = node;
        Head->next = node;
    }
    DoubleLinkedList* RemoveTail()
    {
        DoubleLinkedList* node = Tail->pre;
        RemoveNode(node);
        return node;
    }
};