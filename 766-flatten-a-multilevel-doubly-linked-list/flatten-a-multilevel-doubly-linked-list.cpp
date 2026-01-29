/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
void flat(Node *a){
    Node* b = a->child;
    Node *c;
    while(b!=0){
        if(b->child!=0){
            flat(b);
        }
        c=b;
        b=b->next;
    }
    b=c;
    b->next = a->next;
    if(a->next!=0){
        a->next->prev = b;
    }
    a->child->prev = a;
    a->next = a->child;
    a->child = 0;
    return;
}
class Solution {
public:
    Node* flatten(Node* head) {
        Node *a = head;
        while(a!=0){
            if(a->child!=0){
                flat(a);
            }
            a=a->next;
        }
        return head;
    }
};