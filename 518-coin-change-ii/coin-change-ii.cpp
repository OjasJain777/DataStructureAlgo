int t(int amt, int i, vector<vector<int>> &dp, vector<int> &coins){
    if(amt==0){
        return 1;
    }
    if(amt<0){
        return 0;
    }
    if(i==coins.size()){
        return 0;
    }
    if(dp[amt][i]!=-1){
        return dp[amt][i];
    }
    int a = t(amt - coins[i], i, dp, coins);
    int b = t(amt, i+1, dp, coins);
    return dp[amt][i]=a+b;
}
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size(),-1));
        return t(amount, 0, dp, coins);
    }
};