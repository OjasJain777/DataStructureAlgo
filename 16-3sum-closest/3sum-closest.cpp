class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cd = INT_MAX;
        int cs;
        for(int i =0; i<nums.size()-2;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int l = i+1;
            int r = nums.size()-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                int d = target-sum;
                if(abs(d)<cd){
                    cd=abs(d);
                    cs = sum;
                }
                if(d<0){
                    r--;
                }
                else if(d>0){
                    l++;
                }
                else{
                    return sum;
                }
            }
        }
        return cs;
    }
};