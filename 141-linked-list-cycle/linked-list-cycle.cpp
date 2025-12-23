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
    bool hasCycle(ListNode *head) {
        int a= INT_MIN;
        ListNode *b = head;
        if(b==0){
            return false;
        }
        while(b->next!=NULL){
            if(b->next->val == a){
                return true;
            }
            b->val = a;
            b=b->next;
        }
        return false;
    }
};