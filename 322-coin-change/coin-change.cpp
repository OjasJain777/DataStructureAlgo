int t(int target, int k, vector<vector<int>> &dp, vector<int> &coins){
    if(target<0){
        return 1e9;
    }
    if(target == 0){
        return dp[target][k] = 0;
    }
    if(k<0){
        return 1e9;
    }
    if(dp[target][k] != -1){
        return dp[target][k];
    }
    int a = t(target - coins[k],k, dp, coins) +1;
    int b = t(target, k-1, dp,coins);
    return dp[target][k] = min(a,b);
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1,-1));
        int a = t(amount,coins.size()-1, dp, coins);
        return a >= 1e9 ? -1 : a;
    }
};