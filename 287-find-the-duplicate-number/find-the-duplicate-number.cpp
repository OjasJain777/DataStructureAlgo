#include <set>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> a;
        for(int i =0;i<nums.size();i++){
            a.insert(nums[i]);
            if(i+1 != a.size()){
                return nums[i];
            }
        }
        return 0;
    }
};