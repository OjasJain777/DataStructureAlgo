int f(int i, string &a, int t,int b,int s, vector<vector<vector<vector<int>>>> &dp){
    if(i==a.size()){
        return b;
    }
    int ans =0;
    if(dp[i][t][b][s] !=-1){
        return dp[i][t][b][s];
    }
    int d;
    if(t==1){
        d = a[i]-'0';
    }
    else{
        d = 10;
    }
    int st;
    if(b==0){
        st = 1;
    }
    else{
        st=0;
    }
    if(!b){
        ans += f(i+1, a,0,0,s, dp);
    }
    for(int k = st; k<=d;k++){
        if(k==10){
            continue;
        }
        if ((s & (1 << k)) != 0){
            continue;
        }
        int ns = s | (1<<k);
        if(k==d){
            ans += f(i+1, a,1,1,ns,dp);
        }
        else{
            ans += f(i+1, a, 0, 1,ns, dp);
        }
    }
    return dp[i][t][b][s] = ans;
}
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string a = to_string(n);
        int l = (1 << 10);
        vector<vector<vector<vector<int>>>> dp(a.size() + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(1 << 10, -1))));
        int s = 0;
        return n - f(0,a,1,0,s, dp);
    }
};