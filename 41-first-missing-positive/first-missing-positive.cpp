class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> a;
        for(int x: nums){
            a.insert(x);
        }
        int i =1;
        int n =0;
        while(n<nums.size()){
            int s = a.size();
            a.insert(i);
            if(a.size()==s){
                i++;
            }
            else{
                return i;
            }
            n++;
        }
        return i;
    }
};