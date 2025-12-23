/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *a= head;
        if(a==0){
            return NULL;
        }
        while(a->next!=NULL){
            if(a->next->val == INT_MIN){
                return a->next;
            }
            a->val = INT_MIN;
            a=a->next;
        }
        return NULL;
    }
};