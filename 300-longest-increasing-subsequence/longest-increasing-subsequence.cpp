int t(int k, int p, vector<int> &nums, vector<vector<int>> &dp){
    if(k==nums.size()){
        return 0;
    }
    if(dp[k][p+1] == -1){
        int a = INT_MIN;
        if(p==-1 || nums[k] > nums[p]){
            a = t(k+1, k, nums, dp)+1;
        }
        int b = t(k+1, p, nums, dp);
        dp[k][p+1] = max(a,b);
    }
    return dp[k][p+1];
}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return t(0, -1, nums, dp);
    }
};