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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *a = head;
        int n =0;
        while(a!=NULL){
            a=a->next;
            n++;
        }
        a=head;
        for(int i =0;i<k-1;i++){
            a=a->next;
        }
        ListNode *b= head;
        for(int i =0;i<n-k;i++){
            b=b->next;
        }
        int h = a->val;
        a->val = b->val;
        b->val=h;
        return head;
    }
};