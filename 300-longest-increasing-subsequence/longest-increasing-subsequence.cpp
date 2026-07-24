class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        dp[0] = 0;
        int ans = 0;
        for(int k = 0; k<nums.size();k++){
            for(int j = k;j>=0;j--){
                if(j==0 || nums[j-1] < nums[k]){
                    dp[k+1] = max(dp[k+1], dp[j]+1);
                    ans = max(ans, dp[k+1]);
                }
            }
        }
        return ans;
    }
};