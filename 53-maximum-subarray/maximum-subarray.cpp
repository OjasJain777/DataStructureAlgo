class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int a=0;
        int ans =INT_MIN;
        for(int x: nums){
            if(a<0){
                a=0;
            }
            a += x;
            ans = max(ans, a);
        }
        return ans;
    }
};