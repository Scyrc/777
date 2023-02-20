//using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode(0);
        ListNode* cur = pre;
        
        int cache = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            int x = l1 == nullptr? 0:l1->val;
            int y = l2 == nullptr? 0:l2->val;
            int sum = cache + x + y;
            cache = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);

            cur = cur->next;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        if(cache>0) cur->next = new ListNode(cache);

        return pre->next;
    }
};