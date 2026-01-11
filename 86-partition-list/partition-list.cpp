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
    ListNode* partition(ListNode* head, int x) {
        vector<int> l;
        vector<int> m;
        ListNode *a = head;
        while(a!=0){
            if(a->val <x){
                l.push_back(a->val);
            }
            else{
                m.push_back(a->val);
            }
            a=a->next;
        }
        a=head;
        for(int i=0;i<l.size();i++){
            a->val = l[i];
            a=a->next;
        }
        for(int i=0;i<m.size();i++){
            a->val = m[i];
            a=a->next;
        }
        return head;
    }
};