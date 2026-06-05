class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t = 0;
        for(auto x: nums){
            t+=x;
        }
        vector<bool> dp(t+1,0);
        dp[0]=1;
        for(int i = 0;i<nums.size();i++){
            for(int j = t; j>=0;j--){
                if(dp[j]!=0 && j+nums[i]<=t){
                    dp[j+nums[i]] = 1;
                    if((j+nums[i]) *2 == t){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};