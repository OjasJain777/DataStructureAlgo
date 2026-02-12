/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void t(set<TreeNode *> &s, TreeNode *a, TreeNode *target){
    if(a==0){
        return;
    }
    s.insert(a);
    if(target->val == a->val){
        return;
    }
    else if(target->val < a->val){
        t(s, a->left, target);
    }
    else{
        t(s, a->right, target);
    }
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        set<TreeNode *> a;
        set<TreeNode *> b;
        t(a, root, p);
        t(b, root, q);
        TreeNode *ans;
        for(TreeNode *x:b){
            if(a.count(x)==1){
                ans = x;
            }
        }
        return ans;
    }
};