class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0;
        int ans =0;
        for(int x: nums){
            if(x==1){
                c++;
            }
            else{
                ans = max(ans, c);
                c=0;
            }
        }
        ans = max(ans, c);
        return ans;
    }
};