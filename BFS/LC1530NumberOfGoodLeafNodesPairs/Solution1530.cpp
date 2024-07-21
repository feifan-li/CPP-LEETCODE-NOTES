#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<deque>

using namespace std;
class Solution {
public:
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    int ans = 0;
    int countPairs(TreeNode* root, int distance) {
        // Build A Graph O(N)
        // and get a list of all leaf nodes
        unordered_map<TreeNode*, vector<TreeNode*>> G;
        unordered_set<TreeNode*> leaf;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop_front();
            if(!cur->left && !cur->right){
                leaf.insert(cur);
            }
            if(cur->left){
                q.push_back(cur->left);
                G[cur].push_back(cur->left);
                G[cur->left].push_back(cur);
            }
            if(cur->right){
                q.push_back(cur->right);
                G[cur].push_back(cur->right);
                G[cur->right].push_back(cur);
            }
        }
        // iterate over all the good node pairs
        for(TreeNode* s: leaf){
            int curDistance = 0;
            deque<TreeNode*> q2;
            unordered_set<TreeNode*> visited;
            q2.push_back(s);
            visited.insert(s);
            while(!q2.empty()){
                int q2Size = q2.size();
                for(int cnt = 0; cnt < q2Size; ++cnt){
                    TreeNode* u = q2.front();
                    q2.pop_front();
                    for(TreeNode* v: G[u]){
                        if(!visited.count(v)){
                            visited.insert(v);
                            q2.push_back(v);
                            if(curDistance+1 <= distance && leaf.count(v)){
                                ans ++;
                            }
                        }
                    }
                }
                curDistance ++;
                if(curDistance >= distance){
                    break;
                }
            }
        }
        return ans/2;
    }
};