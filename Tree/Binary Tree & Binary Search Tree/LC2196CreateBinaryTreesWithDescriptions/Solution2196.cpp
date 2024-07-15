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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_map<int, int> parentMap;
        for(vector<int> relation: descriptions){
            int parentVal = relation[0];
            if(nodeMap.find(parentVal)==nodeMap.end()){
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            int childVal = relation[1];
            if(nodeMap.find(childVal)==nodeMap.end()){
                nodeMap[childVal] = new TreeNode(childVal);
            }
            parentMap[childVal] = parentVal;
            if(relation[2]==1){
                nodeMap[parentVal]->left = nodeMap[childVal];
            }else{
                nodeMap[parentVal]->right = nodeMap[childVal];
            }
        }
        for(vector<int> relation: descriptions){
            if(!parentMap[relation[0]]){
                return nodeMap[relation[0]];
            }
        }
        return nullptr;
    }
};