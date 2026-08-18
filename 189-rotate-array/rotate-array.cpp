class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        for(int i =0; i<n-k;i++){
            nums.push_back(nums[i]);
        }
        int i = 0;
        int j = n-k;
        int m = nums.size();
        while(i<m){
            if(i<n){
                nums[i] = nums[j];
                i++;
                j++;
            }
            else{
                nums.pop_back();
                i++;
            }
        }
    }
};