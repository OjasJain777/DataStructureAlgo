int t(int s, int e, int p, vector<int> &nums,vector<vector<int>> &dp){
    if(s>e){
        return 0;
    }
    if(dp[s][e] !=INT_MIN){
        return dp[s][e];
    }
    if(p){
        dp[s][e] = max(nums[s] + t(s+1,e,0,nums,dp) , nums[e] + t(s,e-1,0,nums,dp));
    }
    else{
        dp[s][e] = min( t(s+1,e,1,nums,dp) - nums[s] , t(s,e-1,1,nums,dp) - nums[e]);
    }
    return dp[s][e];
}
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(),INT_MIN));
        t(0, nums.size()-1, 1,nums, dp);
        return dp[0][nums.size()-1] >=0 ? 1 : 0;
    }
};