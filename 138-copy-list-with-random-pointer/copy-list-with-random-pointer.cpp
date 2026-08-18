/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* he) {
        Node *head = he;
        unordered_map<Node *, Node*> m;
        Node *t = 0;
        Node *h = 0;
        while(head!=0){
            Node *n = new Node(head->val);
            if(h==0){
                h=n;
                t=n;
            }
            else{
                t->next = n;
                t=n;
            }
            m[head] = n;
            head=head->next;
        }
        while(he!=0){
            m[he]->random = m[he->random];
            he=he->next;
        }
        return h;
    }
};