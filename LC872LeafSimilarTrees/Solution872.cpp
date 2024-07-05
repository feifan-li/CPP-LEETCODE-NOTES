#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        dfs(root1,list1);
        dfs(root2,list2);

        return list1==list2;
    }
    void dfs(TreeNode* root, vector<int>& list){
        if(root->left == nullptr && root->right==nullptr){list.push_back(root->val);}
        if(root->left != nullptr) {dfs(root->left,list);}
        if(root->right != nullptr) {dfs(root->right,list);}
    }
};


int main(){


}