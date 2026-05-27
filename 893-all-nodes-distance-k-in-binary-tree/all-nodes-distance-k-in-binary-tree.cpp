/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, vector<TreeNode *>> adj;
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()!=0){
            auto y= q.front();
            q.pop();
            if(y->left!=0){
                q.push(y->left);
                adj[y].push_back(y->left);
                adj[y->left].push_back(y);
            }
            if(y->right!=0){
                q.push(y->right);
                adj[y].push_back(y->right);
                adj[y->right].push_back(y);
            }
        }
        queue<pair<int, TreeNode *>> q1;
        q1.push({0, target});
        while(q1.size()!=0){
            auto [d,y]= q1.front();
            q1.pop();
            if(adj[y].empty()){
                continue;
            }
            if(d==k){
                ans.push_back(y->val);
                continue;
            }
            for(int x = adj[y].size()-1;x>=0; x--){
                q1.push({d+1, adj[y][x]});
                adj[y].pop_back();
            }            
        }
        return ans;
    }
};