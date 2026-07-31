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
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> s;
        for(auto &x: d){
            s.insert(x[1]);
            if(m[x[0]] == 0){
                m[x[0]] = new TreeNode(x[0]);
            }
            if(m[x[1]] == 0){
                m[x[1]] = new TreeNode(x[1]);
            }
            if(x[2]==1){
                m[x[0]]->left = m[x[1]];
            }
            else{
                m[x[0]]->right = m[x[1]];
            }
        }
        TreeNode *root;
        for(auto &x: d){
            if(s.count(x[0])==0){
                root = m[x[0]];
                break;
            }
        }
        return root;
    }
};