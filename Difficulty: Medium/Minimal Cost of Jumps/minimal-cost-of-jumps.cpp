class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0]=0;
        for(int i =1; i<n;i++){
            for(int j =k; j>0;j--){
                if(i-j<0){
                    continue;
                }
                dp[i] = min(dp[i], dp[i-j] + abs(arr[i] - arr[i-j]));
            }
        }
        return dp[n-1];
    }
};