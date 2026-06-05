bool t(int k, int s, int r,int &sum, map<pair<int,int>, bool> &dp, vector<int> &arr){
    if(s>sum){
        return 0;
    }
    if(s+r < sum){
        return 0;
    }
    if(s==sum){
        return 1;
    }
    if(k>= arr.size()){
        return 0;
    }
    if(dp.count({k,s})!=0){
        return dp[{k,s}];
    }
    dp[{k,s}] = t(k+1, s, r-arr[k], sum,dp,arr) ||t(k+1, s+arr[k], r-arr[k], sum, dp,arr);
    return dp[{k,s}];
}
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int r=0;
        for(auto x : arr){
            r+=x;
        }
        map<pair<int,int>,bool> dp;
        return t(0, 0, r, sum, dp, arr);
    }
};