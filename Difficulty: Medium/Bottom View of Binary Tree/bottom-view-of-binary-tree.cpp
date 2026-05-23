/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        map<int, int> b;
        vector<int> ans;
        queue<pair<int,Node *>> q;
        if(root==0){
            return ans;
        }
        q.push({0,root});
        while(q.size()!=0){
            auto [v,t]  = q.front();
            q.pop();
            b[v] = t->data;
            if(t->left!=0){
                q.push({v-1, t->left});
            }
            if(t->right !=0){
                q.push({v+1, t->right});
            }
        }
        for(auto y: b){
            ans.push_back(y.second);
        }
        return ans;
    }
};