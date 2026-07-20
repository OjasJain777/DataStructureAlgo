class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum =0;
        long long m = 0;
        int n = nums.size();
        for(int i =0; i<n;i++){
            sum += nums[i];
            m += i*nums[i];
        }
        long long ma = m;
        for(int i =1; i<n;i++){
            m = m + sum - 1LL*nums[n-i]*n;
            ma = max(ma, m);
        }
        return ma;
    }
};