class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int r = nums.size()-1;
        while(s<=r){
            int m = (s+r)/2;
            if(nums[m]<=nums[r]){
                if(m==0){
                    return nums[m];
                }
                else if(nums[m-1]>nums[m]){
                    return nums[m];
                }
                else{
                    r = m-1;
                }
            }
            else{
                s = m+1;
            }
        }
        return 0;
    }
};