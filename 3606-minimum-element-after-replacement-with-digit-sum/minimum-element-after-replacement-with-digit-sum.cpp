int t(int k){
    int a = 0;
    while(k!=0){
        a += k%10;
        k/=10;
    }
    return a;
}
class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i =0 ; i<nums.size();i++){
            nums[i] = t(nums[i]);
        }
        int mi = INT_MAX;
        for(int x: nums){
            mi = min(mi, x);
        }
        return mi;
    }
};