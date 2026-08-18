class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans = 0;
        int s =0;
        m[0]=1;
        for(int x: nums){
            s+=x;
            ans += m[s-k];
            m[s]++;
        }
        return ans;
    }
};