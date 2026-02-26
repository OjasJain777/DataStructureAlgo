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
int t(TreeNode *a){
    if(a==0){
        return 0;
    }
    return max(t(a->left),t(a->right)) +1;
}
void d(TreeNode *a, int &i){
    if(a==0){
        return;
    }
    else if(t(a->left)==0 && t(a->right)==0){
        return;
    }
    else if(t(a->left) - t(a->right) <=1 && t(a->left) - t(a->right) >=-1){
        i *=1;
    }
    else{
        i*=0;
        return;
    }
    d(a->left, i);
    d(a->right, i);
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int i =1;
        d(root, i);
        return i;
    }
};