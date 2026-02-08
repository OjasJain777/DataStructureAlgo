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

void t(map<int,vector<int>> &b, Node *a, int i, int j){
    if(a==0){
        return;
    }
    if(b.count(j)==0){
        b[j] = {i,a->data};
    }
    else{
        if(i<b[j][0]){
            b[j][0]=i;
            b[j][1]=a->data;
        }
    }
    t(b, a->left, i+1, j-1);
    t(b, a->right, i+1, j+1);
}

class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int, vector<int>> b;
        t(b,root, 0,0);
        vector<int> ans;
        for(auto y:b){
            ans.push_back(y.second[1]);
        }
        return ans;
    }
};