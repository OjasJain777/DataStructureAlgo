class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> a;
        for(int x: nums){
            if(a.count(x)!=0){
                return 1;
            }
            a.insert(x);
        }
        return 0;
    }
};