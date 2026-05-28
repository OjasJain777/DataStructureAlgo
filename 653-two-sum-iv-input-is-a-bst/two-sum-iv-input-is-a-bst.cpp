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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> m;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()!=0){
            auto y= q.front();
            q.pop();
            if(m[k-y->val]==1){
                return 1;
            }
            m[y->val]++;
            if(y->left){
                q.push(y->left);
            }
            if(y->right){
                q.push(y->right);
            }
        }
        return 0;
    }
};