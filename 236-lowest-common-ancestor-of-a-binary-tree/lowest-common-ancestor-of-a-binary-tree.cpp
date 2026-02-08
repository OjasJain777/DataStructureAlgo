/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool t(TreeNode *a, set<TreeNode *> &ans, int target){
    if(a==0){
        return 0;
    }
    ans.insert(a);
    if(a->val==target){
        return 1;
    }
    if(t(a->left, ans, target) || t(a->right, ans, target)){
        return 1;
    }

    ans.erase(a);
    return 0;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        set<TreeNode *> ans1;
        set<TreeNode *> ans2;
        t(root, ans1, p->val);
        t(root, ans2, q->val);
        TreeNode *t;
        for(TreeNode *x: ans1){
            if(ans2.count(x)!=0){
                t=x;
            }
        }
        return t;
    }
};