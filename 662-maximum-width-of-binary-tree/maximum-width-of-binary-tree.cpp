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
void t(unordered_map<int,vector<unsigned long long>> &b, TreeNode *a, int i, unsigned long long j){
    if(a==0){
        return;
    }
    b[i].push_back(j);
    t(b, a->left, i+1, 2*j);
    t(b,a->right, i+1, 2*j+1);
}
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, vector<unsigned long long>> b;
        t(b, root, 0,0);
        unsigned long long m = 0;
        for(auto y: b){
            m = max(m, y.second[y.second.size()-1] - y.second[0] + 1);
        }
        return m;
    }
};