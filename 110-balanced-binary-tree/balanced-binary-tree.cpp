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
    else{
        int p = t(a->left,f);
        int k = t(a->right,f);
        int g = p-k;
        if(g<-1 || g>1){
            f=0;
        }
        return (max(p,k))+1;
    }
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int f =1;
        t(root, f);
        if(f==0){
            return 0;
        }
        return 1;
    }
};