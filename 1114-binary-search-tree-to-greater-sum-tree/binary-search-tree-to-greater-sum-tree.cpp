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
void t(TreeNode *a, int &sum){
    if(a==0){
        return;
    }
    t(a->right, sum);
    sum += a->val;
    a->val= sum;
    t(a->left,sum);
}
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum =0;
        t(root, sum);
        return root;
    }
};