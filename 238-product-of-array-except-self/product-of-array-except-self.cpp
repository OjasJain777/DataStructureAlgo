class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int product=1;
        for(int x:nums){
            ans.push_back(product);
            product *= x;
        }
        product = 1;
        for(int i = nums.size()-1;i>0;i--){
            product *= nums[i];
            ans[i-1] = ans[i-1] * product;
        }
        return ans;
    }
};