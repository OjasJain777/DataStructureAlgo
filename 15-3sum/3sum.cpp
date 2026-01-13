class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i =0;
        int l;
        vector<vector<int>> ans;
        int r;
        while(i<nums.size()-2){
            int target = (-1)*(nums[i]);
            if(i==0){
                l = i+1;
                r = nums.size()-1;
            }
            else if(nums[i]==nums[i-1]){
                l=0;
                r=0;
            }
            else{
                l=i+1;
                r=nums.size()-1;
            }
            while(l<r){
                if(nums[l] + nums[r] == target){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    while(l<nums.size()-1 && nums[l+1]==nums[l] ){
                        l++;
                    }
                    while(r>0 && nums[r-1]==nums[r] ){
                        r--;
                    }
                    r--;
                    l++;
                }
                else if(nums[l] + nums[r] > target){
                    while(r>0 && nums[r-1]==nums[r]){
                        r--;
                    }
                    r--;
                }
                else{
                    while(l<nums.size()-1 && nums[l+1]==nums[l]){
                        l++;
                    }
                    l++;
                }

            }
            i++;
        }
        return ans;
    }
};