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

bool t(TreeNode *a, TreeNode *b){
    if(a==0 && b==0){
        return 1;
    }
    else if(a==0 || b==0){
        return 0;
    }
    else if(a->val != b->val){
        return 0;
    }
    bool c  = t(a->left, b->right);
    bool d = t(a->right, b->left);
    return c*d;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return t(root, root);
    }
};