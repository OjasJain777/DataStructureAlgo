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
int t(TreeNode *a, bool &b){
    if(a==0){
        return 0;
    }
    int l  = t(a->left,b);
    int r = t(a->right,b);
    if(abs(l-r) <= 1){
        b *= 1;
    }
    else{
        b*=0;
    }
    return max(l,r)+1;
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool b=1;
        t(root, b);
        return b;
    }
};