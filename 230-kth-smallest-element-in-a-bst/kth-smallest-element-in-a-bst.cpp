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
void t(vector<int> &arr, TreeNode *a, int k){
    if(a==0){
        return;
    }
    t(arr, a->left,k);
    arr.push_back(a->val);
    t(arr,a->right,k);
    if(arr.size()==k){
        return;
    }
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        t(ans, root, k);
        return ans[k-1];
    }
};