class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()<3){
            return nums.size();
        }
        int m = INT_MIN;
        int a = 2;
        for(int i =2;i<nums.size();i++){
            if(nums[i] == nums[i-1] + nums[i-2]){
                a++;
            }
            else{
                m = max(m,a);
                a=2;
            }
        }
        m=max(m,a);
        return m;
    }
};