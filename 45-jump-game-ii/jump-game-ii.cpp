class Solution {
public:
    int jump(vector<int>& nums) {
        int s = 0;
        int ma = 0;
        int ans = 0;
        if(nums.size()==1){
            return 0;
        }
        while(s<nums.size()){
            int t = ma;
            ans++;
            for(int i = s;i<=ma;i++){
                t = max(t, nums[i] + i);
            }
            if(t >= nums.size()-1){
                return ans;
            }
            s = ma+1;
            ma = t;
        }
        return 0;
    }
};