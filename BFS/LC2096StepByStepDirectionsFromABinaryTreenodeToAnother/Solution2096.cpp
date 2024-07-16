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
    unordered_map<int, vector<int>> G;
    deque<char> path;
    string ans;
    string getDirections(TreeNode* root, int startValue, int destValue) {
        //Use BFS to build a graph G
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop_front();
            if(G.find(cur->val)==G.end()){
                vector<int> neighbours(3,-1);
                G[cur->val] = neighbours;
            }
            if(cur->left){
                G[cur->val][0] = cur->left->val;
                if(G.find(cur->left->val)==G.end()){
                    vector<int> neighbours(3,-1);
                    G[cur->left->val] = neighbours;
                }
                G[cur->left->val][2] = cur->val;
                q.push_back(cur->left);
            }
            if(cur->right){
                G[cur->val][1] = cur->right->val;
                if(G.find(cur->right->val)==G.end()){
                    vector<int> neighbours(3,-1);
                    G[cur->right->val] = neighbours;
                }
                G[cur->right->val][2] = cur->val;
                q.push_back(cur->right);
            }
        }
        //Use DFS to find dest and construct a path
        vector<bool> visited(G.size()+1, false);
        dfs(startValue, destValue, visited);
        return ans;
    }
    void dfs(int s, int t, vector<bool>& visited){
        // cout << s << endl;
        visited[s] = true;
        if(s == t){
            string tmp(path.begin(), path.end());
            ans = tmp;
            return;
        }
        if(G[s][0]>0 && !visited[G[s][0]]){
            path.push_back('L');
            dfs(G[s][0],t,visited);
        }
        if(G[s][1]>0 && !visited[G[s][1]]){
            path.push_back('R');
            dfs(G[s][1],t,visited);
        }
        if(G[s][2]>0 && !visited[G[s][2]]){
            path.push_back('U');
            dfs(G[s][2],t,visited);
        }
        path.pop_back();
    }
};