class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> m(n);
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        if(n>1){
            dp[1]=nums[1];
            m[1]=max(nums[0],nums[1]);
        }
        m[0] = nums[0];
        for(int k =2; k<n;k++){
            dp[k] = max(dp[k], m[k-2] + nums[k]);
            m[k] = max(m[k-1], dp[k]);
        }
        return m[n-1];
    }
};