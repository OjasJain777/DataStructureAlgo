class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;
        for(int x:nums){
            if(x>0){
                p.push_back(x);
            }
            else{
                n.push_back(x);
            }
        }
        int pp=0;
        int np = 0;
        for(int i =0;i<nums.size();i++){
            if(i%2==0){
                nums[i] = p[pp];
                pp++;
            }
            else{
                nums[i] = n[np];
                np++;
            }
        }
        return nums;
    }
};