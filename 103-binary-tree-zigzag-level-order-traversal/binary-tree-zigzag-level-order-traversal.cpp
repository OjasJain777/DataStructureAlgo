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
        queue<int> q1;
        stack<int> st;
        if(root==0){
            return ans;
        }
        q.push(root);
        q1.push(root->val);
        int i =0;
        while(q.size()!=0){
            vector<int> a;
            int n =q.size();
            for(int k =0; k< n;k++){
                if(i==0){
                    auto y = q.front();
                    q.pop();
                    auto x = q1.front();
                    q1.pop();
                    a.push_back(x);
                    if(y->left!=0){
                        q.push(y->left);
                        st.push(y->left->val);
                    }
                    if(y->right!=0){
                        q.push(y->right);
                        st.push(y->right->val);
                    }
                }
                else{
                    auto y = q.front();
                    q.pop();
                    auto x = st.top();
                    st.pop();
                    a.push_back(x);
                    if(y->left!=0){
                        q.push(y->left);
                        q1.push(y->left->val);
                    }
                    if(y->right!=0){
                        q.push(y->right);
                        q1.push(y->right->val);
                    }
                }               
            }
            ans.push_back(a);
            i=(i+1)%2;
        }
        return ans;
    }
};