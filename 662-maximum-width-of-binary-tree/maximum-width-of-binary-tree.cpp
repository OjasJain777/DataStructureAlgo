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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<unsigned long long, TreeNode *>> q;
        q.push({0,root});
        int ans =1;
        queue<pair<unsigned long long, TreeNode *>> q1;
        unsigned long long  mi = ULLONG_MAX;
        unsigned long long ma = 0;
        while(q.size()!=0){
            auto [v,t] = q.front();
            q.pop();
            mi = min(mi, v);
            ma = max(ma, v);
            if(t->left!=0){
                q1.push({2*v,t->left});
            }
            if(t->right!=0){
                q1.push({2*v+1, t->right});
            }
            if(q.size()==0){
                q = q1;
                q1={};
                int d = (int)(ma-mi+1);
                mi = ULLONG_MAX;
                ma = 0;
                ans = max(d, ans);
            }
        }
        return ans;
    }
};