void t(unordered_map<int, vector<int>> &m, unordered_set<int> &s, int k, int &ans){
    if(k==0){
        ans++;
        return;
    }
    for(int x: m[k]){
        if(s.count(x)==1){
            continue;
        }
        s.insert(x);
        t(m, s, k-1, ans);
        s.erase(x);
    }
}
class Solution {
public:
    int countArrangement(int n) {
        unordered_map<int, vector<int>> m;
        for(int i = 1; i<=n ;i++){
            for(int j = 1; j<=n;j++){
                if(i%j==0 || j%i==0){
                    m[i].push_back(j);
                }
            }
        }
        unordered_set<int> s;
        int ans =0;
        t(m,s,n, ans);
        return ans;
    }
};