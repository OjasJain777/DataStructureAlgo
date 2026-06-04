vector<int> dx = {-1,0};
vector<int> dy = {0, -1};
int t(int i, int j, vector<vector<int>> &dp){
    if(i==0 && j == 0){
        return 1;
    }
    if(dp[i][j] == 0){
        dp[i][j]=0;
        for(int k = 0; k<2;k++){
            if(i+dx[k]>=0 && i+dx[k]<dp.size() && j+dy[k]>=0 && j+dy[k] < dp[0].size()){
                dp[i][j] += t(i+dx[k], j+dy[k], dp);
            }
        }
    }
    return dp[i][j];
}
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        return t(m-1, n-1, dp);
    }
};