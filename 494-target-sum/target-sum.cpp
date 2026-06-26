class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> dp(2001,0);
        target = target + 1000;
        dp[1000] = 1;
        for(int x: nums){
            vector<int> c(2001,0);
            for(int j = 2000; j>=0;j--){
                if(dp[j] != 0){
                    if(j+x<=2000){
                        c[j+x] += dp[j];
                    }
                    if(j-x>=0){
                        c[j-x] += dp[j];
                    }
                }
            }
            dp=c;
        }
        return dp[target];
    }
};