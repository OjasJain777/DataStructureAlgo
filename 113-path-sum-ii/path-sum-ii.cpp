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
void t(TreeNode *c, unordered_map<int, vector<vector<int>>> &b, vector<int> a, int sum){
    if(c==0){
        return;
    }
    if(c->right == 0 && c->left == 0){
        sum += c->val;
        a.push_back(c->val);
        b[sum].push_back(a);
        return;
    }
    sum += c->val;
    a.push_back(c->val);
    t(c->left, b,a , sum);
    t(c->right, b, a, sum);
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, vector<vector<int>>> b;
        vector<int> a;
        int sum =0;
        t(root, b, a , sum);
        return b[targetSum];
    }
};