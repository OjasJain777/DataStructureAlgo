class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int i =0;
        sort(nums.begin(),nums.end());
        int j =0;
        int m = 1;
        while(i<nums.size() && j<nums.size()){
            if((long long)nums[i]*k >= (long long)nums[j]){
                m = max(m, j-i+1);
                j++;
            }
            else{
                i++;
            }
        }
        return nums.size()-m;
    }
};