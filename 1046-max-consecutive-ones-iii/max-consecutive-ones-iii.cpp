class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int e =0;
        int s = 0;
        int c = k;
        int ans=0;
        while(e<nums.size()){
            if(nums[e]==0){
                if(c==0){
                    while(c==0){
                        if(nums[s]==0){
                            c++;
                        }
                        s++;
                    }
                }
                e++;
                c--;
            }
            else{
                e++;
            }
            ans=max(ans, e-s);
        }
        return ans;
    }
};