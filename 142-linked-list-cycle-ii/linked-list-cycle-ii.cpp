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
        ListNode *a = head;
        while(a!=0 && a->val != INT_MIN){
            a->val = INT_MIN;
            a=a->next;
        }
        return a;
    }
};