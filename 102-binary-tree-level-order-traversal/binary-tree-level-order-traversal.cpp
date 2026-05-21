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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()!=0){
            int n = q.size();
            vector<int> a;
            for(int k =0; k<n;k++){
                auto y = q.front();
                q.pop();
                if(y==0){
                    continue;
                }
                a.push_back(y->val);
                q.push(y->left);
                q.push(y->right);
            }
            ans.push_back(a);
        }
        ans.pop_back();
        return ans;
    }
};