int t(int s, int e, int p, vector<int> &nums, vector<vector<vector<int>>> &dp){
    if(s>e){
        return 0;
    }
    if(dp[s][e][p] != INT_MIN){
        return dp[s][e][p];
    }
    if(p){
        dp[s][e][p] = max(t(s+1,e,0,nums, dp) + nums[s], t(s,e-1,0,nums,dp) + nums[e]);
    }
    else{
        dp[s][e][p] = max(t(s+1,e,1,nums,dp) - nums[s] , t(s,e-1,1,nums,dp) - nums[e]);
    }
    return dp[s][e][p];
}
class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>> (nums.size(), vector<int>(2, INT_MIN)));
        t(0, nums.size()-1, 1, nums,dp);
        return dp[0][nums.size()-1][1] >0 ? 1 : 0;
    }
};