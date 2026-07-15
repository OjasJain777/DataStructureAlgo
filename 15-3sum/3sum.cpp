class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i<nums.size();i++){
            if(i!=0 && nums[i] == nums[i-1]){continue;}
            int s= i+1;
            int e  = nums.size()-1;
            while(e>s){
                if(nums[e]+nums[s]+nums[i]==0){
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    e--;
                    while(s < e && nums[s] == nums[s-1]){
                        s++;
                    }
                    while(e>s && nums[e] == nums[e+1]){
                        e--;
                    }
                }
                else if(nums[s]+nums[e]+nums[i] < 0){
                    s++;
                    while(s < e && nums[s] == nums[s-1]){
                        s++;
                    }
                }
                else{
                    e--;
                    while(e>s && nums[e] == nums[e+1]){
                        e--;
                    }
                }
            }
        }
        return ans;
    }
};