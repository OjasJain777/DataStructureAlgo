class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s =0;
        for(int x: nums){
            s+=x;
        }
        int n = nums.size();
        int t = ((n)*(n+1))/2;
        return t-s;
    }
};