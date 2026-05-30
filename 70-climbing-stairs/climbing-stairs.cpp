int fib(int n, vector<int> &dp){
    if(n==0){
        return 1;
    }
    if(n==-1){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fib(n-1, dp)+fib(n-2, dp);
    return dp[n];
}
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return fib(n, dp);
    }
};