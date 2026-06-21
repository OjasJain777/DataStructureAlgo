int t(vector<int> &nums, vector<int> &dp, int n){
    if(n==0){
        return nums[0];
    }
    if(n==1){
        return max(nums[0], nums[1]);
    }
    if(dp[n]==-1){
        dp[n] = max(t(nums, dp,n-1) , nums[n] + t(nums,dp,n-2));
    }
    return dp[n];
}
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return t(nums, dp, nums.size()-1);
    }
};