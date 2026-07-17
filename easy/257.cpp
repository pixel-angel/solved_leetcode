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

//recursive dfs :>

vector <string> ans;

void dfs(TreeNode *curr, string s){
    if(!curr->left && !curr->right){
        s+=to_string(curr->val);
        ans.push_back(s);
        return;
    }
    s+=to_string(curr->val)+"->";
    if(curr->left){
        dfs(curr->left,s);
    }
    if(curr->right){
        // s+=to_string(curr->val)+"-"
        dfs(curr->right,s);
    }
}

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return ans;
        
    }
};