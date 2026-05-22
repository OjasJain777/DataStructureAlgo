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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<vector<int>>> b;
        queue<pair<int, pair<int,TreeNode *>>> q;
        vector<vector<int>> ans;
        if(root==0){
            return ans;
        }
        q.push({0, {0,  root}});
        while(q.size()!=0){
            auto j = q.front();
            int v = j.first;
            int l = j.second.first;
            TreeNode *a = j.second.second;
            q.pop();
            if(l+1>b[v].size()){
                for(int k =b[v].size(); k<l;k++){
                    b[v].push_back({});
                }
                b[v].push_back({a->val});
            }
            else{b[v][b[v].size()-1].push_back(a->val);}
            if(a->left!=0){
                q.push({v-1, {l+1, a->left}});
            }
            if(a->right!=0){
                q.push({v+1, {l+1, a->right}});
            }
        }
        for(auto y: b){
            vector<int> a;
            for(auto &g: y.second){
                sort(g.begin(), g.end());
                for(auto c: g){
                    a.push_back(c);
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};