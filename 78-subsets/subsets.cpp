void sub(vector<int> &arr, vector<int> &a,vector<vector<int>> &ans, int i ){
    if(i==arr.size()){
        ans.push_back(a);
        return;
    }
    a.push_back(arr[i]);
    sub(arr, a,ans, i+1);
    a.pop_back();
    sub(arr,a,ans,i+1);
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        vector<vector<int>> ans;
        sub(nums, a, ans, 0);
        return ans;
    }
};