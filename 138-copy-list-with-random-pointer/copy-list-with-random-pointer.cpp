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
    Node* copyRandomList(Node* head) {
        Node *a = head;
        Node *temp = 0;
        Node *head1 = 0;
        unordered_map<Node*, Node*> store;
        while(a!=NULL){
            Node *newnode = new Node(a->val);
            if(temp==0){
                head1 = newnode;
                temp= newnode;
            }
            else{
                temp->next = newnode;
                temp = newnode;
            }
            store[a] = newnode;
            a=a->next;
        }
        a = head;
        Node *b = head1;
        while(a!=NULL){
            if(a->random == NULL){
                b->random = NULL;
            }
            else{
                b->random = store[a->random];
            }
            b=b->next;
            a=a->next;
        }
        return head1;
    }
};