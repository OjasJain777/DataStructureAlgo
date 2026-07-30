class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int ma = INT_MIN;
        int mi = INT_MAX;
        for(int x: nums){
            ma = max(ma, x);
            mi = min(mi , x);
        }
        return 1LL*(ma-mi)*k;
    }
};