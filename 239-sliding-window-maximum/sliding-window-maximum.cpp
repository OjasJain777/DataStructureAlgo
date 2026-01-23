class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> a;
        vector<int> ans;
        for(int i=0;i<k;i++){
            a[nums[i]]++;
        }
        auto it = prev(a.end());
        int m = it->first;
        ans.push_back(m);
        int j = k;
        int i = 0;
        while(j<nums.size()){
            a[nums[j]]++;
            if(a[nums[i]]==1){
                a.erase(nums[i]);
            }
            else{
                a[nums[i]]--;
            }
            auto its = prev(a.end());
            m = its->first;
            ans.push_back(m);
            j++;
            i++;
        }
        return ans;
    }
};