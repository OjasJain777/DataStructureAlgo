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
void t(map<int, TreeNode*> &b, vector<int> &a, TreeNode *c){
    if(c==0){
        return;
    }
    t(b, a, c->left);
    a.push_back(c->val);
    b[c->val] = c;
    t(b, a, c->right);
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        map<int, TreeNode*> b;
        vector<int> a;
        t(b, a, root);
        int i =0;
        vector<TreeNode*> d;
        for(auto y: b){
            if(y.first != a[i]){
                d.push_back(y.second);
            }
            i++;
        }
        int g = d[0]->val;
        d[0]->val = d[1]->val;
        d[1]->val = g;
    }
};