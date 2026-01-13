class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = nums[0];
        int n=0;
        int j =0;
        for(int i =0;i<nums.size();i++){
            if(c==nums[i]){
                n++;
            }
            else{
                n=1;
                c=nums[i];
            }
            if(n<=2){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};