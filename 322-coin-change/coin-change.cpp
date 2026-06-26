int t(int amt, vector<int> &dp, vector<int> &coins){
    if(amt == 0){
        return 0;
    }
    if(amt<0){
        return INT_MAX -1 ;
    }
    if(dp[amt] != -1){
        return dp[amt];
    }
    int ans = INT_MAX;
    for (int x : coins) {
        int c = t(amt - x, dp, coins);
        if (c != INT_MAX) {
            ans = min(ans, c + 1);
        }
    }
    return dp[amt] = ans;
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int a = t(amount, dp, coins);
        return a == INT_MAX ? -1 : a;
    }
};