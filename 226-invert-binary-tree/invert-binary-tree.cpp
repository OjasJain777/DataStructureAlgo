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

TreeNode *t(TreeNode *a){
    if(!a){
        return 0;
    }
    TreeNode *b = t(a->left);
    TreeNode *c = t(a->right);
    a->left = c;
    a->right = b;
    return a;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return t(root);
    }
};