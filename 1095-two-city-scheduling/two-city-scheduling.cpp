int t(int i, int k, vector<vector<int>> &c, vector<vector<int>> &dp){
    if(i==0){
        if(k== c.size()/2){
            return c[0][1];
        }
        else if(k == c.size()/2-1){
            return c[0][0];
        }
        return 1e9;
    }
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    if(k== c.size()/2){
        dp[i][k] = t(i-1, k, c,dp) + c[i][1];
    }
    else{
        dp[i][k] = min(t(i-1, k+1, c, dp) + c[i][0] , t(i-1,k,c,dp)+c[i][1]);
    }
    return dp[i][k];
}
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(costs.size(), vector<int>(costs.size()/2+1,-1));
        return t(costs.size()-1, 0, costs, dp);
    }
};