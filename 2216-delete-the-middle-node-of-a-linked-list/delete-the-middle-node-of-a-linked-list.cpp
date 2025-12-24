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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==0){
            return 0;
        }
        else if(head->next==0){
            return 0;
        }
        ListNode *a = head;
        int l =0;
        while(a!=NULL){
            l++;
            a=a->next;
        }
        a=head;
        for(int i =0;i<l/2 -1;i++){
            a=a->next;
        }
        a->next = a->next->next;
        return head;
    }
};