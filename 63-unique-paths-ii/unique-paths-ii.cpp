class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        vector<int> dp(o[0].size(),0);
        if(o[0][0]==1){
            return 0;
        }
        dp[0]=1;
        for(int i =0; i<o.size();i++){
            for(int j =0; j<dp.size();j++){
                if(o[i][j]==1){
                    dp[j]=0;
                }
                else if(j==0){
                    continue;
                }
                else{
                    dp[j] = dp[j-1] + dp[j];
                }
            }
        }
        return dp.back();
    }
};