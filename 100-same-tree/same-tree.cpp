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
    if(a==0 & b==0){
        return 1;
    }
    if(a==0 || b==0){
        return 0;
    }
    if(a->val!=b->val){
        return 0;
    }
    return (t(a->left, b->left) && t(a->right, b->right));
}
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return t(p,q);
    }
};