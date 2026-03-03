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
 TreeNode *root = 0;
TreeNode *t(vector<int> &a, int s, int e){
    int mid = (s+e)/2;
    TreeNode *newnode = new TreeNode(a[mid]);
    if(s>e){
        return 0;
    }
    newnode->left = t(a, s, mid-1);
    newnode->right = t(a,mid+1,e);
    return newnode;
}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        root = t(nums, s, e);
        return root;
    }
};