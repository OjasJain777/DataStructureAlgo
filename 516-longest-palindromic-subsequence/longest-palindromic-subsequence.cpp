int t(int i, int j, string &s, vector<vector<int>> &dp){
    if(i>j){return 0;}
    if(i==j){return 1;}
    if(dp[i][j]==-1){
        if(s[i]==s[j]){
            dp[i][j] = 2 + t(i+1, j-1,s,dp);
        }
        else{
            dp[i][j] = max(t(i+1, j, s, dp), t(i,j-1, s,dp));
        }
    }
    return dp[i][j];
}
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        return t(0, s.size()-1, s, dp);
    }
};