class Solution {
public:
    vector<vector<int>> dp;
    int sol(int i , int j , vector<int> & nums){
        if(i>j) return 0;
        if(i==j)  return  nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int first = nums[i]+ min(sol(i+2,j, nums),sol(i+1,j-1,nums));
        int second = nums[j]+ min(sol(i,j-2, nums),sol(i+1,j-1,nums));
        return  dp[i][j]=max(first,second);
    }
    bool stoneGame(vector<int>& nums) {
        return true;
        int total=0;
        for(int i : nums) total+=i;
        dp.assign(501,vector<int> (501,-1));
        int a= sol(0,nums.size()-1, nums);
        return a>=(total-a);
    }
};