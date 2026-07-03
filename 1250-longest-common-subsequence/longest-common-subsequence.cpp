int t(string &s1, string &s2, int k1, int k2, vector<vector<int>> &dp){
    if(k1 ==- 1 || k2==-1){
        return 0;
    }
    if(dp[k1][k2]!=-1){
        return dp[k1][k2];
    }
    if(s1[k1]==s2[k2]){
        dp[k1][k2]= 1 + t(s1,s2,k1-1,k2-1,dp);
    }
    else{
        dp[k1][k2] = 0 + max(t(s1,s2,k1-1,k2,dp), t(s1,s2,k1,k2-1,dp));
    }
    return dp[k1][k2];
}
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return t(text1, text2, text1.size()-1, text2.size()-1, dp);
    }
};