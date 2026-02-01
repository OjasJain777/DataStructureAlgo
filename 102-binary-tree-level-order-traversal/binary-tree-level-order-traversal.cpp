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

void t(TreeNode *a, map<int, vector<int>> &b,int i){
    if(a==0){
        return;
    }
    b[i].push_back(a->val);
    t(a->left, b, i+1);
    t(a->right, b, i+1);
}
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int,vector<int>> b;
        vector<vector<int>> ans;
        t(root, b, 0);
        for(auto y: b){
            ans.push_back(y.second);
        }
        return ans;
    }
};