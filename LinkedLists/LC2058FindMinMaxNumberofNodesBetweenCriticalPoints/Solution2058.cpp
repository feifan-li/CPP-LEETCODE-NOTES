class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        int min = INT_MAX;
        int max = INT_MIN;
        int cur_pos = 0;//0-indexed position of cur_node
        int last_pos = -1;//position of last critical point
        int first_critical_pos = -1;
        ListNode* cur_node = head;
        ListNode* prev_node = nullptr;
        ListNode* next_node = cur_node->next;
        while(cur_node != nullptr){
            if(prev_node != nullptr && next_node != nullptr){
                if((cur_node->val>prev_node->val && cur_node->val>next_node->val) || 
                    (cur_node->val<prev_node->val && cur_node->val<next_node->val)){
                    //found a critical point
                    if(first_critical_pos==-1){
                        last_pos = cur_pos;
                        first_critical_pos = cur_pos;
                    }else{
                        min = ((cur_pos-last_pos)>=min)?min:(cur_pos-last_pos);
                        max = ((cur_pos-first_critical_pos)<=max)?max:(cur_pos-first_critical_pos);
                        last_pos = cur_pos;
                    }
                }
            }
            prev_node = cur_node;
            cur_node = next_node;
            next_node = (cur_node==nullptr)?nullptr:cur_node->next;
            cur_pos ++;
        }
        if(max<min){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(min);
        ans.push_back(max);
        return ans;
    }
};