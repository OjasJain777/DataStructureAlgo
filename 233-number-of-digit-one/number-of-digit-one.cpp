int f(int i, string &a, int t,int c, vector<vector<vector<int>>> &dp){
    if(i==a.size()){
        return c;
    }
    if(dp[i][t][c]!=-1){
        return dp[i][t][c];
    }
    int ans = 0;
    int d;
    if(t==1){d = a[i]-'0';}
    else{
        d = 10;
    }
    for(int j = 0; j<=d;j++){
        if(j==10){
            continue;
        }
        if(j==d){
            if(j==1){
                ans += f(i+1,a,1,c+1,dp);
            }
            else{
                ans += f(i+1, a, 1, c, dp);
            }
        }
        else{
            if(j==1){
                ans += f(i+1,a,0,c+1,dp);
            }
            else{
                ans += f(i+1, a,0, c, dp);
            }
        }
    }
    return dp[i][t][c]=ans;
}
class Solution {
public:
    int countDigitOne(int n) {
        string a = to_string(n);
        vector<vector<vector<int>>> dp(a.size()+1, vector<vector<int>>(2, vector<int>(a.size()+1,-1)));
        return f(0, a,1, 0, dp);
    }
};