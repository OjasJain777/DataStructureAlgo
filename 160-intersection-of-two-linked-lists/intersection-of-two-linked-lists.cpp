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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> s;
        ListNode *a = headA;
        while(a!=0){
            s.insert(a);
            a=a->next;
        }
        a = headB;
        while(a!=0){
            if(s.count(a)==1){
                return a;
            }
            a=a->next;
        }
        return 0;
    }
};