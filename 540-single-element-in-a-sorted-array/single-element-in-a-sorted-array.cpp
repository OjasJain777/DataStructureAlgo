class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l =0;
        int r = nums.size()-1;
        int n = nums.size();
        while(l<=r){
            int mid = (l+r)/2;
            if(l==r){
                return nums[l];
            }
            else if((n/2)%2==0){
                if(nums[mid-1] == nums[mid]){
                    r=mid;
                }
                else{
                    l = mid;
                }
                n = n/2 + 1;
            }
            else{
                if(nums[mid-1] == nums[mid]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
                n=n/2;
            }
        }
        return 0;
    }
};