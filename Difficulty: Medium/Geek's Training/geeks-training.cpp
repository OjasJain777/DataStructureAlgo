int t(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i==mat.size()-1){
        return mat[i][j];
    }
    if(dp[i][j]==INT_MIN){
        for(int k =0;k<mat[0].size();k++){
            if(j==k){
                continue;
            }
            dp[i][j] = max(dp[i][j], mat[i][j] + t(i+1, k,mat, dp));
        }
    }
    return  dp[i][j];
}
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(),INT_MIN));
        int ans = INT_MIN;
        for(int j =0; j<mat[0].size();j++){
            ans = max(ans, t(0, j, mat, dp));
        }
        return ans;
    }
};