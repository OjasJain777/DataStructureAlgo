class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        int i =0;
        int j =0;
        int p;
        a.push_back(INT_MAX);
        b.push_back(INT_MAX);
        while(i!= a.size()-1 || j != b.size()-1){
            if(a[i]<=b[j]){
                if(ans.size()==0 || p!=a[i]){
                    ans.push_back(a[i]);
                    p=a[i];
                }
                i++;
            }
            else if(b[j] < a[i]){
                if(ans.size()==0 || p!=b[j]){
                    ans.push_back(b[j]);
                    p=b[j];
                }
                j++;
            }
        }
        return ans;
    }
};