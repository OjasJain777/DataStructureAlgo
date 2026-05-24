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
void t(TreeNode *a){
    if(a==0){
        return;
    }
    t(a->left);
    t(a->right);
    TreeNode *b = a->right;
    a->right = a->left;
    a->left = 0;
    while(a->right){
        a=a->right;
    }
    a->right = b;
}
class Solution {
public:
    void flatten(TreeNode* root) {
        t(root);
    }
};