class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind;
        int mini = INT_MAX;
        for(int i=0; i<nums.size();i++){
            if(nums[i]<mini){
                mini = nums[i];
                ind = i;
            }
        }
        int k = ind;
        
        vector<int> n;
        for(int i =0;i<nums.size();i++){
            n.push_back(nums[ind]);
            ind = (ind+1)%nums.size();
        }
        
        int l =0;
        int r = n.size()-1;
        ind = -1;
        while(l<=r){
            int mid = (l+r)/2;
            if(n[mid] == target){
                ind = mid;
                break;
            }
            else if(n[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if(ind == -1){
            return ind;
        }
        else{
            return ((ind+k)%nums.size());
        }
    }
};