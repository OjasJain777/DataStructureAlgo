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
TreeNode *t(vector<int> &p, vector<int> &i, int &j, int s, int e){
    if(s>e){
        return 0;
    }
    TreeNode *a = new TreeNode(p[j]);
    int k =s;
    while(k<=e){
        if(i[k]==p[j]){
            j++;
            break;
        }
        k++;
    }
    if(k<=e){
        a->left = t(p,i,j, s, k-1);
        a->right= t(p,i,j,k+1, e);
    }
    return a;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int j =0;
        return t(preorder, inorder, j, 0, inorder.size()-1);
    }
};