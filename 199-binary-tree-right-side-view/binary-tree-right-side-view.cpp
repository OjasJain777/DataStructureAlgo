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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==0){
            return ans;
        }
        queue<pair<int, TreeNode*>> q;
        q.push({0,root});
        int l=0;
        while(q.size()!=0){
            int n = q.size();
            for(int k =0;k<n;k++){
                auto [v, t] = q.front();
                q.pop();
                if(t->left!=0){
                    q.push({v-1, t->left});
                }
                if(t->right!=0){
                    q.push({v+1, t->right});
                }
                if(k==n-1){
                    ans.push_back(t->val);
                }
            }
        }
        return ans;
    }
};