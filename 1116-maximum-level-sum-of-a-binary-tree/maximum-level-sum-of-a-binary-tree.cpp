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

void t(TreeNode *a, map<int, int> &b, int i){
    if(a==0){
        return;
    }
    b[i] += a->val;
    t(a->left, b, i+1);
    t(a->right, b, i+1);
}
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        map<int,int> b;
        t(root, b,0);
        int m = INT_MIN;
        int j;
        for(auto y: b){
            if(y.second>m){
                m = y.second;
                j=y.first;
            }
        }
        return j+1;
    }
};