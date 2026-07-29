class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> dp(arr.size(),0);
        dp[start]=1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            auto y = q.front();
            q.pop();
            if(arr[y] == 0){
                return 1;
            }
            if(y - arr[y] >=0 && dp[y-arr[y]] ==0 ){
                dp[y-arr[y]] =1;
                q.push(y-arr[y]);
            }
            if(y+arr[y] < arr.size() && dp[y+arr[y]] ==0 ){
                dp[y+arr[y]] = 1;
                q.push(y+arr[y]);
            }
        }
        return 0;
    }
};