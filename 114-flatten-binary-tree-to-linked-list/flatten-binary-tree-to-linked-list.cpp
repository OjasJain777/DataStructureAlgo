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
void t(TreeNode *a, vector<TreeNode*> &b){
    if(a==0){
        return;
    }
    b.push_back(a);
    t(a->left,b);
    t(a->right, b);
}

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> b;
        t(root, b);
        root=0;
        TreeNode *temp = 0;
        for(TreeNode *x: b){
            if(root==0){
                root=x;
                temp=x;
            }
            else{
                temp->right = x;
                temp=x;
            }
            temp->left=0;
        }
    }
};