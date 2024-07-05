class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    ListNode* mergeNodes(ListNode* head) {
        //recursion
        //upon the entry of this function, head->val must be zero
        if(head->next==nullptr){
            return nullptr;
        }
        ListNode* p = head->next;
        int sum = 0;
        while(p->val!=0){
            sum += p->val;
            p = p->next;
        }
        head->val = sum;
        head->next = mergeNodes(p);
        return head;
    }
};