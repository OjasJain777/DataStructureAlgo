class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int t =0;
        for(auto x: arr){
            t+=x;
        }
        int s = t;
        t=t/2;
        vector<bool> dp(t+1, 0);
        dp[0]=1;
        for(int i =0;i<arr.size();i++){
            for(int j = t;j>=0;j--){
                if(dp[j]!=0 && j+arr[i]<=t){
                    dp[j+arr[i]] = 1;
                }
            }
        }
        for(int k = t;k>=0;k--){
            if(dp[k] == 1){
                return abs(s - 2*k);
            }
        }
        return 0;
    }
};
