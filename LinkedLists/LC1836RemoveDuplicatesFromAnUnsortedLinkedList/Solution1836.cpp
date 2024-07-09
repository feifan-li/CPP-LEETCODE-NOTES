/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        unordered_map<int,int> map;
        ListNode* cur = head;
        while(cur!=nullptr){
            // if(map.find(cur->val)==map.end()){
            //     map.insert(pair<int,int>(cur->val,1));
            // }else{
            //     map[cur->val] = map[cur->val]+1;
            // }
            map[cur->val]++;
            cur = cur->next;
        }
        ListNode* dummy = new ListNode(-1,head); 
        ListNode* prev = dummy;
        cur = head;
        while(cur!=nullptr){
            if(map[cur->val]<=1){
                prev = cur;
            }else{
                prev->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};