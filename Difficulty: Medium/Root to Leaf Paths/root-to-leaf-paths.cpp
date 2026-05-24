/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        stack<pair<int,Node *>> st;
        vector<vector<int>> ans;
        if(root==0){
            return ans;
        }
        st.push({0,root});
        vector<int> a;
        a.push_back(root->data);
        while(st.size()!=0){
            auto [d, t] = st.top();
            if(t->left==0 && t->right ==0){
                ans.push_back(a);
                st.pop();
                a.pop_back();
                continue;
            }
            if(d==0){
                st.pop();
                st.push({1, t});
                if(t->left!=0){
                    st.push({0,t->left});
                    a.push_back(t->left->data);
                }
            }
            else if(d==1){
                st.pop();
                st.push({2, t});
                if(t->right !=0){
                    st.push({0, t->right});
                    a.push_back(t->right->data);
                }
            }
            else if(d==2){
                st.pop();
                a.pop_back();
            }
        }
        return ans;
    }
};