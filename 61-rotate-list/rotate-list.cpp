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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *a = head;
        int l =0;
        if(a==0){
            return 0;
        }
        while(a!=NULL){
            l++;
            a=a->next;
        }
        a=head;
        while(a->next != 0){
            a=a->next;
        }
        a->next = head;
        a= head;
        ListNode *b = NULL;
        for(int i =0;i<l-(k%l);i++){
            b=a;
            a=a->next;
        }
        b->next = 0;
        head = a;
        return head;
    }
};