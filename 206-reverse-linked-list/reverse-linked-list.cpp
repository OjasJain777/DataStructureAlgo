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
ListNode* t(ListNode *a, ListNode *&h){
    if(a->next == 0){
        h = a;
        return a;
    }
    t(a->next,h)->next = a;
    return a;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==0){
            return 0;
        }
        t(head, head)->next = 0;
        return head;

    }
};