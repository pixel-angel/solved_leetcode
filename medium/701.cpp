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
    TreeNode* insertIntoBST(TreeNode* root, int x) {

        if(root == NULL) return new TreeNode(x);  // ⭐ FIX

        TreeNode *curr = root;
        TreeNode *parent = NULL;

        TreeNode *p = new TreeNode(x);

        while(curr){
            parent = curr;
            if(x >= curr->val)
                curr = curr->right;
            else
                curr = curr->left;
        }

        if(x >= parent->val)
            parent->right = p;
        else
            parent->left = p;

        return root;
    }
};