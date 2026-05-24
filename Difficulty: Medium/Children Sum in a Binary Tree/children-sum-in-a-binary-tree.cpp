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
int t(Node *a, bool &b){
    if(a==0){
        return 0;
    }
    if(a->left==0 && a->right ==0){
        return a->data;
    }
    if(a->data != t(a->left,b) + t(a->right,b)){
        b*=0;
    }
    return a->data;
}
class Solution {
  public:
    bool isSumProperty(Node *root) {
        bool b = 1;
        t(root, b);
        return b;
    }
};