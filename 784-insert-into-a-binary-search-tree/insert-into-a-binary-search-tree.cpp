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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *a = new TreeNode(val);
        if(root==0){
            return a;
        }
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            auto y = st.top();
            if(y==0){
                st.pop();
                y = st.top();
                if(y->val < val){
                    y->right= a;
                    break;
                }
                else if(y->val>=val){
                    y->left = a;
                    break;
                }
            }
            if(y->val >= val){
                st.push(y->left);
            }
            else{
                st.push(y->right);
            }
        }
        return root;
    }
};