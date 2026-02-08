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
void t(vector<int> &ans, TreeNode *a, int &i){
    if(a==0){
        return;
    }
    t(ans, a->left, i);
    ans.push_back(a->val);
    a->val = i;
    i++;
    t(ans, a->right,i);
}
void h(TreeNode *a, vector<int> &s){
    if(a==0){
        return;
    }
    a->val = s[a->val];
    h(a->left, s);
    h(a->right, s);
}
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> ans;
        int i =0;
        t(ans, root, i);
        int sum = 0;
        for(int j = ans.size()-1;j>=0;j--){
            sum += ans[j];
            ans[j] = sum;
        }
        h(root, ans);
        return root;
    }
};