void subset(vector<int>& arr, vector<int>& a, set<vector<int>>& ans, int i){
    if(i==arr.size()){
        ans.insert(a);
        return;
    }
    a.push_back(arr[i]);
    subset(arr, a, ans, i+1);
    a.pop_back();
    subset(arr,a,ans,i+1);
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> a;
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        subset(nums, a, ans, 0);
        vector<vector<int>> b;
        for(vector<int> x: ans){
            b.push_back(x);
        }
        return b;
    }
};