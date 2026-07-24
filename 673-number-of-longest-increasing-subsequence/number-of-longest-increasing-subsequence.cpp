class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        vector<int> p(nums.size()+1,0);
        dp[0]=0;
        p[0]=1;
        int ans = 0;
        for(int k = 0; k<nums.size();k++){
            for(int j = 0; j<=k;j++){
                if(j==0 || nums[k] > nums[j-1]){
                    if(dp[k+1] < dp[j]+1){
                        dp[k+1] = dp[j]+1;
                        p[k+1] = p[j];
                    }
                    else if(dp[k+1] == dp[j]+1){
                        p[k+1] += p[j];
                    }
                    ans = max(ans, dp[k+1]);
                }
            }
        }
        int a = 0;
        for(int i = 0; i<dp.size();i++){
            if(dp[i]==ans){
                a += p[i];
            }
        }
        return a;
    }
};