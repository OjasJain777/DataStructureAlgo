class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int e = 0;
        int s =0;
        int c =0;
        int ze=0;
        int ans =0;
        while(e<nums.size()){
            if(nums[e]==1){
                e++;
                c++;
            }
            else{
                if(ze == k){
                    while(ze==k){
                        if(nums[s]==0){
                            c--;
                            s++;
                            ze--;
                        }
                        else{
                            c--;
                            s++;
                        }
                    }
                }
                else{
                    c++;
                    e++;
                    ze++;
                }
            }
            ans = max(ans,c);
        }
        return ans;
    }
};