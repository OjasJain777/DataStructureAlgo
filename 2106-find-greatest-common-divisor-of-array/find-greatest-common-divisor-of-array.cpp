class Solution {
public:
    int findGCD(vector<int>& nums) {
        int ans;
        int ma = INT_MIN;
        int mi = INT_MAX;
        for(int x: nums){
            mi = min(mi,x);
            ma = max(ma,x);
        }
        for(int i = 1; i<=mi;i++){
            if(mi%i==0 && ma%i==0){
                ans = i;
            }
        }
        return ans;
    }
};