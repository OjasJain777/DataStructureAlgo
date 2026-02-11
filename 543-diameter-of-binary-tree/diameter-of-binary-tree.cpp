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
int t(TreeNode *a, int &f){
    if(a==0){
        return 0;
    }
    int p = t(a->left, f);
    int k = t(a->right, f);
    f = max(f, p+k);
    return (max(p,k)+1);
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int f = 0;
        t(root,f);
        return f;
    }
};