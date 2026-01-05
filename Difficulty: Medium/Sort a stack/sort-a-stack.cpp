class Solution {
  public:
    void sortStack(stack<int> &st) {
        vector<int> a;
        while(!st.empty()){
            a.push_back(st.top());
            st.pop();
        }
        sort(a.begin(),a.end());
        for(int i = 0;i<a.size();i++){
            st.push(a[i]);
        }
    }
};
