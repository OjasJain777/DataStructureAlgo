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
void t(map<int, map<int, vector<int>>> &b, TreeNode *a, int i, int j){
    if(a==0){
        return;
    }
    b[j][i].push_back(a->val);
    t(b, a->left, i+1, j-1);
    t(b,a->right, i+1, j+1);
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> b;
        t(b, root, 0,0);
        vector<vector<int>> ans;
        for(auto y: b){
            vector<int> m;
            for(auto x: y.second){
                sort(x.second.begin(), x.second.end());
                m.insert(m.end(), x.second.begin(), x.second.end());
            }
            ans.push_back(m);
        }
        return ans;
    }
};