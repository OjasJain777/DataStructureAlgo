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
void t(vector<int> &arr, TreeNode *a){
    if(a==0){
        return;
    }
    t(arr, a->left);
    arr.push_back(a->val);
    t(arr, a->right);
}
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> a;
        t(a, root);
        int m = INT_MAX;
        for(int i =1; i<a.size();i++){
            m = min(m, a[i]-a[i-1]);
        }
        return m;
    }
};