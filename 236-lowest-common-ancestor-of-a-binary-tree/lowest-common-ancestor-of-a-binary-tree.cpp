/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void t(TreeNode *a, TreeNode *f, unordered_set<TreeNode *> &s, int &c){
    if(c==1){
        return;
    }
    if(a==0){
        return;
    }
    if(a==f){
        c=1;
        s.insert(a);
        return;
    }
    s.insert(a);
    t(a->left, f, s, c);
    t(a->right, f, s, c);
    if(c==0){
        s.erase(a);
    }
}
void t1(TreeNode *a, TreeNode *f, vector<TreeNode *> &s, int &c){
    if(c==1){
        return;
    }
    if(a==0){
        return;
    }
    if(a==f){
        c=1;
        s.push_back(a);
        return;
    }
    s.push_back(a);
    t1(a->left, f, s, c);
    t1(a->right, f, s, c);
    if(c==0){
        s.pop_back();
    }
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int c = 0;
        unordered_set<TreeNode *> s;
        vector<TreeNode *> v;
        t(root, p, s, c);
        c=0;
        t1(root, q, v, c);
        for(int i = v.size()-1; i>=0 ;i--){
            if(s.count(v[i])!=0){
                return v[i];
            }
        }
        return root;
    }
};