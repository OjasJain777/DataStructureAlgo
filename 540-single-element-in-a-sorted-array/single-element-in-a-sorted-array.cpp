class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l =0;
        int r = nums.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            if((m==0 || nums[m-1]!=nums[m]) && (m==nums.size()-1 || nums[m] != nums[m+1])){
                return nums[m];
            }
            else if(m != nums.size()-1 && nums[m] == nums[m+1]){
                if((m-l)%2==0){
                    l = m+2;
                }
                else{
                    r=m-1;
                }
            }
            else{
                if((m-l)%2==0){
                    r=m-2;
                }
                else{
                    l=m+1;
                }
            }
        }
        return -1;
    }
};