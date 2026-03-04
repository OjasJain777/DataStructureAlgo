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
int i =0;
vector<int> a;
void t(TreeNode *b){
    if(b==0){
        return;
    }
    t(b->left);
    a.push_back(b->val);
    t(b->right);
}
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        i=0;
        a = {};
        t(root);
    }
    
    int next() {
        i++;
        return a[i-1];
    }
    
    bool hasNext() {
        if(i<a.size()){
            return 1;
        }
        return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */