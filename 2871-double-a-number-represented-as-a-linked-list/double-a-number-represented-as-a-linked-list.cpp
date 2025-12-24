/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode *c = head;
        ListNode *b = 0;
        ListNode *a = 0;
        while(c!=NULL){
            a=b;
            b=c;
            c=c->next;
            b->next = a;
        }
        int carry = 0;
        head = b;
        a=head;
        ListNode *s = 0;
        ListNode *t=0;
        int m =0;
        while(a!=NULL){
            m = (a->val)*2 + carry;
            ListNode* newnode = new ListNode(m%10);
            if(s==0){
                s=newnode;
                t=s;
            }
            else{
                t->next = newnode;
                t=newnode;
            }
            carry=m/10;
            a=a->next;
            if(a==0 && carry ==1){
                ListNode* newnode = new ListNode(carry);
                t->next = newnode;
            }
        }
        c=s;
        b=0;
        while(c!=NULL){
            a=b;
            b=c;
            c=c->next;
            b->next = a;
        }
        s=b;
        return s;
    }
};