/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node *, Node *> p;
        queue<Node *> q;
        Node *t;
        unordered_map<Node*, bool> v;
        q.push(root);
        while(q.size()!=0){
            auto y = q.front();
            q.pop();
            if(y->data == target){
                t = y;
            }
            if(y->left !=0){
                q.push(y->left);
                p[y->left] = y;
            }
            if(y->right != 0){
                q.push(y->right);
                p[y->right] = y;
            }
        }
        queue<pair<int, Node *>> q1;
        q1.push({0, t});
        v[t]=1;
        while(q1.size()!=0){
            auto [d,y] = q1.front();
            q1.pop();
            if(y->left!=0 && v[y->left]==0){
                q1.push({d+1, y->left});
                v[y->left]=1;
            }
            if(y->right !=0 && v[y->right]==0){
                q1.push({d+1, y->right});
                v[y->right]=1;
            }
            if(p[y]!=0 && v[p[y]]==0){
                q1.push({d+1, p[y]});
                v[p[y]] =1;
            }
            if(q1.empty()){
                return d;
            }
        }
        return 0;
    }
};