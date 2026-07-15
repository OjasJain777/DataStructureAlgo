class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r  = nums[0];
        int ma = 1;
        int mi =1;
        for(int x: nums){
            int tmp = ma*x;
            ma = max({x, ma*x, mi*x});
            mi = min({x, mi*x, tmp});
            r = max(r, ma);
        }
        return r;
    }
};