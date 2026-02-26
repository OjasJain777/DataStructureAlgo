class Solution {
public:
    int reverseBits(int n) {
        vector<int> nums;
        while(n>=1){
            nums.push_back(n%2);
            n=n/2;
        }
        while(nums.size()!=32){
            nums.push_back(0);
        }
        long long k=1;
        long long ans = 0;
        for(int i =nums.size()-1;i>=0;i--){
            ans += (k*nums[i]);
            k=k*2;
        }
        return ans;
    }
};