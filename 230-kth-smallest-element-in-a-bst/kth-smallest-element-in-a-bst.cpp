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
    if(arr.size()==k){
        return;
    }
    t(arr, a->left,k);
    if(arr.size()==k){
        return;
    }
    arr.push_back(a->val);
    if(arr.size()==k){
        return;
    }
    t(arr,a->right,k);
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        t(ans, root, k);
        return ans[ans.size()-1];
    }
};