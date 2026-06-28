class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1 << nums.size();
        vector<vector<int>> ans;
        for(int k =0; k<n;k++){
            int c = k;
            int i=0;
            vector<int> a;
            while(c!=0){
                if(c & 1){
                    a.push_back(nums[i]);
                }
                c = c >> 1;
                i++;
            }
            ans.push_back(a);
        }
        return ans;
    }
};