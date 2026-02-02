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
void t(TreeNode *a,  vector<int> &ans, int i){
    if(a==0){
        return;
    }
    if(i>ans.size()){
        ans.push_back(a->val);
    }
    else{
        ans[i-1] += a->val;
    }
    t(a->left, ans, i+1);
    t(a->right, ans, i+1);
}
class Solution {
public:
    int maxLevelSum(TreeNode* root){
        int m = INT_MIN;
        int j =0;
        vector<int> ans;
        t(root, ans, 1);
        for(int i =0; i<ans.size();i++){
            if(ans[i]>m){
                m=ans[i];
                j= i+1;
            }
        }
        return j;
    }
};