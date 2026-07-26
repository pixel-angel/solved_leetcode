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
int ans=0;
void dfs(TreeNode* curr,int level){
    if(curr == nullptr) return;
    if(!curr->left && !curr->right){
        ans=max(level,ans);
    }
    if(curr->left){
        dfs(curr->left,level+1);
    }
    if(curr->right){
        dfs(curr->right,level+1);
    }
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        ans=0;
        dfs(root,1);
        return ans;
        
    }
};