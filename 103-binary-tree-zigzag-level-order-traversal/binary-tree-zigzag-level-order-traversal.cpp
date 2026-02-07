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
void t(map<int, vector<int>> &b, TreeNode *a, int i){
    if(a==0){
        return;
    }
    b[i].push_back(a->val);
    t(b, a->left, i+1);
    t(b, a->right, i+1);
}
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        map<int, vector<int>> b;
        t(b, root, 0);
        int c =1;
        vector<vector<int>> ans;
        for(auto y: b){
            if(c==1){
                ans.push_back(y.second);
            }
            else{
                reverse(y.second.begin(), y.second.end());
                ans.push_back(y.second);
            }
            c*=(-1);
        }
        return ans;
    }
};