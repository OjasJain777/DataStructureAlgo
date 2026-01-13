class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i =0;
        int j = nums.size()-1;
        vector<int> ans= {-1,-1};
        while(i<=j){
            int m = (i+j)/2;
            if(nums[m]==target && m ==0){
                ans[0] = m;
                break;
            }
            else if(nums[m] == target && nums[m-1] != nums[m]){
                ans[0] = m;
                break;
            }
            else if(nums[m] == target && nums[m-1] == nums[m]){
                j=m-1;
            }
            else if(nums[m] >target){
                j=m-1;
            }
            else{
                i=m+1;
            }
        }
        i=0;
        j=nums.size()-1;
        while(i<=j){
            int m = (i+j)/2;
            if(nums[m] == target && m==nums.size()-1){
                ans[1] = m;
                break;
            }
            else if(nums[m] == target && nums[m+1] != nums[m]){
                ans[1] = m;
                break;
            }
            else if(nums[m] == target && nums[m+1] == nums[m]){
                i=m+1;
            }
            else if(nums[m] >target){
                j=m-1;
            }
            else{
                i=m+1;
            }
        }
        return ans;
    }
};