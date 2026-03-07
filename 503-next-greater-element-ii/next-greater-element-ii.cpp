class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> a1(nums.size(),-1);
        vector<int> a;
        for(int k = nums.size()-1;k>=0;k--){
            a.push_back(k);
        }
        for(int k = nums.size()-1;k>=0;k--){
            while(a.size()>0 && nums[k] >= nums[a[a.size()-1]]){
                a.pop_back();
            }
            if(a.size()==0){
                a1[k] = -1;
            }
            else{
                a1[k] = nums[a[a.size()-1]];
            }
            a.push_back(k);
        }
        return a1;
    }
};