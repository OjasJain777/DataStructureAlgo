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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *a = head;
        ListNode *d = 0;
        for(int i =1; i<left;i++){
            d=a;
            a=a->next;
        }
        ListNode *c =0;
        ListNode *e = head;
        for(int i =1; i<=right;i++){
            e=e->next;
        }
        ListNode*b =e;
        while(a!=e){
            c=b;
            b=a;
            a=a->next;
            b->next = c;
        }
        if(left==1){
            head = b;
        }
        if(d!=0){
        d->next = b;
        }
        return head;
    }
};