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

TreeNode *t(int s, int e, vector<int> &p, vector<int> &i, int &j){
    if(j>=p.size()){
        return 0;
    }
    TreeNode *newnode= new TreeNode(p[j]);
    if(s>e){
        return 0;
    }
    int k =s;
    while(i[k] != p[j]){
        k++;
    }
    j++;
    newnode -> left = t(s, k-1, p, i, j);
    newnode -> right = t(k+1, e, p, i, j);
    return newnode;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int j =0;
        int s = 0;
        int e = preorder.size()-1;
        return t(s, e, preorder, inorder,j);
    }
};