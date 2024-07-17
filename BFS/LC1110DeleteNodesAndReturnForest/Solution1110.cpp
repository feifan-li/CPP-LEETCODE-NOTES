/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //to delete a node x, need to know its parent node first
        //delete a node x, then its children becomes new root
        vector<TreeNode*> ans;
        unordered_set<int> pendingDelete;
        for(int v: to_delete){
            pendingDelete.insert(v);
        }
        if(pendingDelete.find(root->val)==pendingDelete.end()){
            ans.push_back(root);
        }
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop_front();
            if(cur->left){
                q.push_back(cur->left);
                if(pendingDelete.find(cur->val)!=pendingDelete.end()){
                    if(pendingDelete.find(cur->left->val)==pendingDelete.end()){
                        ans.push_back(cur->left);
                    }
                    cur->left = nullptr;
                }else if(pendingDelete.find(cur->left->val)!=pendingDelete.end()){
                    cur->left = nullptr;
                }
            }
            if(cur->right){
                q.push_back(cur->right);
                if(pendingDelete.find(cur->val)!=pendingDelete.end()){
                    if(pendingDelete.find(cur->right->val)==pendingDelete.end()){
                        ans.push_back(cur->right);
                    }
                    cur->right = nullptr;
                }else if(pendingDelete.find(cur->right->val)!=pendingDelete.end()){
                    cur->right = nullptr;
                }
            }
        }
        return ans;
    }
};