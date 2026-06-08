/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // function joh root lega kissi bhi subtree ka aur left ko utha ke right me
    // insert krdega
    void lefttoright(TreeNode* root) {
        if (root->left) {
            // root ke left ka bhi rightmost ka next hoga root ke right ke just
            // phele
            TreeNode* lefthead = root->left;
            TreeNode* curr = root->left;
            while (curr->right)
                curr = curr->right;
            // ab curr ka right would be root ka right
            curr->right = root->right;
            // root ka right would be lefthead
            root->right = lefthead;
            // aur root ka left null krdo
            root->left = NULL;
        }
    }
    void flatten(TreeNode* root) {
        // inplace krna h.
        // toh phele to insert krdo left subtree ko right se phele.

        //now just traverse subtrees.
        TreeNode* curr = root;

         while (curr) {
            lefttoright(curr);
            curr = curr->right;
        }
    }
};