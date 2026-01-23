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
    ListNode* sortList(ListNode* head) {
        vector<int> b;
        ListNode *a = head;
        while(a!=NULL){
            b.push_back(a->val);
            a=a->next;
        }
        a=head;
        int i =0;
        sort(b.begin(),b.end());
        while(a!=NULL){
            a->val = b[i];
            i++;
            a=a->next;
        }
        return head;
    }
};