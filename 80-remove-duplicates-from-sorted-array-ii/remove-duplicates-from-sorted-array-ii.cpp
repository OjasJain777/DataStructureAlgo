class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> a;
        for(int x: nums){
            if(a[x]<2){
                a[x]++;
            }
        }
        int i =0;
        for(auto y: a){
            for(int j =0; j<y.second;j++){
                nums[i] = y.first;
                i++;
            }
        }
        return i;
    }
};