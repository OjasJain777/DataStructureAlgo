int t(int target, vector<int> &dp, vector<int> &coins){
    if(target <0){
        return 1e9;
    }
    if(target==0){
        return dp[target] = 0;
    }
    if(dp[target] != -1){
        return dp[target];
    }
    dp[target] = 1e9;
    for(int x: coins){
        dp[target] = min(dp[target], t(target - x, dp, coins) + 1);
    }
    return dp[target];
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int a= t(amount, dp, coins);
        if(a==1e9){
            return -1;
        }
        return a;
    }
};