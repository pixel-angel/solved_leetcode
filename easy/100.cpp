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
void dfs(TreeNode* curr, vector<int>& v){
    if(!curr){
        v.push_back(100001);   // any value outside constraints
        return;
    }

    v.push_back(curr->val);
    dfs(curr->left, v);
    dfs(curr->right, v);
}

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector <int> dfsp,dfsq;
        dfs(p,dfsp);
        dfs(q,dfsq);
        if(dfsp==dfsq) return 1;
        return 0;
        
    }
};