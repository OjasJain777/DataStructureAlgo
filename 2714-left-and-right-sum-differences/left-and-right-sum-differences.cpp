class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> l;
        int c = 0;
        for(int x: nums){
            l.push_back(c);
            c += x;
        }
        c=0;
        vector<int> r(nums.size());
        for(int i  = nums.size()-1;i>=0;i--){
            r[i] = c;
            c += nums[i];
        }
        for(int i =0 ; i<nums.size();i++){
            nums[i] = abs(l[i]-r[i]);
        }
        return nums;
    }
};