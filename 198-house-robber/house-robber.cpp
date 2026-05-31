class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        if(n>1){dp[1] = nums[1];}
        for(int k =2; k<n;k++){
            for(int j =0; j<k-1;j++){
                dp[k] = max(dp[k], dp[j] + nums[k]);
            }
        }
        int ans =0;
        for(int k: dp){
            ans = max(ans, k);
        }
        return ans;
    }
};