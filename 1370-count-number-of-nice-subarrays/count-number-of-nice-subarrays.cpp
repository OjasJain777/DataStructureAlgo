class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int o=0;
        unordered_map<int,int> m;
        m[0]=1;
        int ans = 0;
        for(int i =0; i<nums.size();i++){
            if(nums[i]%2==1){
                o++;
            }
            if(m[o - k] != 0){
                ans += m[o-k];
            }
            m[o]++;
        }
        return ans;
    }
};