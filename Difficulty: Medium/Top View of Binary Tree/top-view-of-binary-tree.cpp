/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

void t(Node *a, int l, int v, map<int, pair<int, Node *>> &b){
    if(a==0){
        return;
    }
    if(b.count(v)==0){
        b[v] = {l, a};
    }
    else if(b[v].first > l){
        b[v] = {l, a};
    }
    t(a->left, l+1, v-1, b);
    t(a->right, l+1,v+1,b);
}
class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int, pair<int, Node *>> b;
        vector<int> ans;
        t(root, 0,0,b);
        for(auto y: b){
            ans.push_back(y.second.second->data);
        }
        return ans;
    }
};