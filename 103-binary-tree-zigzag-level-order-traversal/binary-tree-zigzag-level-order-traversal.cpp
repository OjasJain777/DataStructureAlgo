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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        if(root==0){
            return ans;
        }
        q.push(root);
        int i =0;
        while(q.size()!=0){
            int n = q.size();
            vector<int> a(n);
            for(int k =0; k<n;k++){
                auto y = q.front();
                q.pop();
                if(i==0){
                    a[k] = y->val;
                }
                else{
                    a[n-k-1] = y->val;
                }
                if(y->left !=0){
                    q.push(y->left);
                }
                if(y->right!=0){
                    q.push(y->right);
                }
            }
            ans.push_back(a);
            i=(i+1)%2;
        }
        return ans;
    }
};