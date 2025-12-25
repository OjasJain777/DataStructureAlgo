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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int x:nums){
            s.insert(x);
        }
        ListNode *a = head;
        ListNode *b = head;
        while(a!=NULL){
            int o = s.size();
            s.insert(a->val);
            if(s.size()==o){
                if(a==head){
                    head=head->next;
                    a=head;
                    b=head;
                }
                else{
                    b->next = a->next;
                    a = a->next;
                }
            }
            else{
                s.erase(a->val);
                b=a;
                a=a->next;
            }
        }
        return head;
    }
};