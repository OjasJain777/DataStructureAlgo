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
bool t(TreeNode *a , TreeNode *b){
    if(a==0 && b==0){
        return 1;
    }
    else if(a==0 || b==0){
        return 0;
    }
    if(a==b){
        return t(a->left, b->right);
    }
    else{
        if(a->val == b->val){
            bool l = t(a->left, b->right);
            bool r = t(a->right, b->left);
            return l && r;
        }
        else{
            return 0;
        }
    }
    return 0;
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return t(root, root);
    }
};