class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int j =0;
        int i =0;
        int c =0;
        while(i< nums.size()-1 && nums[i] < nums[i+1]){
            i++;
            c=1;
        }
        if(c==1){
            j++;
        }
        else{
            return 0;
        }
        c=0;
        while(i<nums.size()-1 && nums[i] > nums[i+1]){
            i++;
            c=1;
        }
        if(c==1){
            j++;
        }
        else{
            return 0;
        }
        c=0;
        while(i<nums.size()-1 && nums[i] < nums[i+1]){
            i++;
            c=1;
        }
        if(c==1){
            j++;
        }
        if(j==3 && i==nums.size()-1){
            return 1;
        }
        return 0;
    }
};