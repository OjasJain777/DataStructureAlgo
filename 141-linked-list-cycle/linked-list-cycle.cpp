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
        ListNode *f = head;
        ListNode *s = head;
        while(f!=0 && f->next!=0){
            f = f->next->next;
            s=s->next;
            if(f==s){
                return 1;
            }
        }
        return 0;
    }
};