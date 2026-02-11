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
    else{
        return (max(t(a->left),t(a->right)))+1;
    }
}

bool b(TreeNode *a){
    if(a==0){
        return 1;
    }
    int g = t(a->right) - t(a->left);
    return ( g<=1 && g >=-1);
}
void c(TreeNode *a, int &f){
    if(a==0){
        return;
    }
    if(b(a)==0){
        f=0;
    }
    c(a->left, f);
    c(a->right, f);
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int f = 1;
        c(root, f);
        if(f==0){
            return 0;
        }
        return 1;
    }
};