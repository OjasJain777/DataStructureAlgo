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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> b;
        ListNode *a = head;
        while(a!=0){
            b[a->val]++;
            a=a->next;
        }
        a=head;
        ListNode *root = 0;
        ListNode *temp = 0;
        for(auto y:b){
            if(y.second==1){
                ListNode* newnode = new ListNode(y.first);
                if(root==0){
                    root= newnode;
                    temp = newnode;
                }
                else{
                    temp->next = newnode;
                    temp = newnode;
                }
            }
        }
        return root;
    }
};