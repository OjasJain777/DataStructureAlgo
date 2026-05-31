class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j =0;
        unordered_set<int> s;
        for(int i =0; i<nums.size();i++){
            if(s.count(nums[i])==0){
                s.insert(nums[i]);
                nums[j] = nums[i];
                j++;
            }
        }
        return s.size();
    }
};