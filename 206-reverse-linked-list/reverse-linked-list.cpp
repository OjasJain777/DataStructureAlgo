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
    ListNode* reverseList(ListNode* head) {
        ListNode *a = NULL;
        ListNode *b = NULL;
        ListNode *c = head;
        while(c!=NULL){
            a=b;
            b=c;
            c=c->next;
            b->next = a;
        }
        return b;
    }
};