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
void t(TreeNode *a, unordered_map<int, int> &b, int sum){
    if(a->right ==0 && a->left ==0){
        sum += a->val;
        b[sum]++;
        return;
    }
    sum += a->val;
    if(a->left !=0){
        t(a->left, b, sum);
    }
    if(a->right != 0){
        t(a->right, b, sum);
    }
}
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==0){
            return 0;
        }
        int sum =0;
        unordered_map<int, int> b;
        t(root, b, sum);
        if(b.count(targetSum) == 0){
            return 0;
        }
        else{
            return 1;
        }
        return 0;
    }
};