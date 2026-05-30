int f(int n, vector<int> &height, vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(n==1){
        return abs(height[1]-height[0]);
    }
    if(dp[n]==-1){
        dp[n] = min(f(n-1,height,dp) + abs(height[n]-height[n-1]), f(n-2,height,dp) + abs(height[n]-height[n-2]));
    }
    return dp[n];
}
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n,-1);
        return f(n-1, height,dp);
    }
};