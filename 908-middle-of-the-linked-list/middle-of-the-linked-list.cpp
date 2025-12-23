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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode *a = head;
        while(a!=NULL){
            count++;
            a=a->next;
        }
        count = count/2;
        for(int i = 0; i<=count;i++){
            if(i==0){
                a= head;
            }
            else{
                a=a->next;
            }
        }
        return a;
    }
};