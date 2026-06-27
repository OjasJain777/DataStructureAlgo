class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp;
        int ans =0;
        for(int i = prices.size()-1;i>=0;i--){
            while(dp.size()!=0 && dp.back() <= prices[i]){
                dp.pop_back();
            }
            if(dp.size()!=0){
                ans = max(ans, dp[0] - prices[i]);
            }
            dp.push_back(prices[i]);
        }
        return ans;
    }
};