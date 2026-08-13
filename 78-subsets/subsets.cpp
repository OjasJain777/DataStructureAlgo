void t(int k, vector<int> &s, vector<int> &a, vector<vector<int>> &ans, int c){
    if(k==s.size()){
        return;
    }
    a.push_back(s[k]);
    ans.push_back(a);
    t(k+1, s,a,ans, c+1);
    a.pop_back();
    t(k+1, s, a, ans,c+0);
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& s) {
        sort(s.begin(), s.end());
        vector<int> a;
        vector<vector<int>> ans;
        ans.push_back(a);
        t(0, s, a,ans,0);
        return ans;
    }
};