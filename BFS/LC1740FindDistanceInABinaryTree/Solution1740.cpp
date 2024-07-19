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
    int findDistance(TreeNode* root, int p, int q) {
        if(p == q){
            return 0;
        }
        //Build a graph
        //does G need to contain all the TreeNodes?
        unordered_map<int, vector<int>> G;
        deque<TreeNode*> q1;
        q1.push_back(root);
        bool pInG = false;
        bool qInG = false;
        while(!q1.empty()){
            TreeNode* cur = q1.front();
            q1.pop_front();
            if(cur->val == p){
                pInG = true;
            }
            if(cur->val == q){
                qInG = true;
            }
            if(pInG & qInG){
                break;
            }
            if(cur->left){
                q1.push_back(cur->left);
                G[cur->val].push_back(cur->left->val);
                G[cur->left->val].push_back(cur->val);
            }
            if(cur->right){
                q1.push_back(cur->right);
                G[cur->val].push_back(cur->right->val);
                G[cur->right->val].push_back(cur->val);
            }
        }
        //BFS
        unordered_set<int> visited;
        visited.insert(p);
        deque<int> q2;
        q2.push_back(p);
        unordered_map<int, int> distMap;
        distMap[p] = 0;
        while(!q2.empty()){
            int cur = q2.front();
            q2.pop_front();
            for(int v: G[cur]){
                if(visited.find(v)==visited.end()){
                    visited.insert(v);
                    q2.push_back(v);
                    distMap[v] = distMap[cur] + 1;
                    if(v == q){
                        return distMap[v];
                    }
                }
            }
        }
        return -2;
    }
};