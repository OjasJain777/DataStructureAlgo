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
void t(TreeNode *a, vector<int> &arr){
    if(a==0){
        return;
    }
    t(a->left, arr);
    arr.push_back(a->val);
    t(a->right, arr);
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        t(root, arr);
        for(int i=0; i<arr.size()-1;i++){
            if(arr[i]>=arr[i+1]){
                return 0;
            }
        }
        return 1;
    }
};