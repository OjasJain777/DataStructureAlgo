void p(vector<int> &arr, vector<int> &a, vector<vector<int>> &ans, int i){
    if(i == arr.size()){
        ans.push_back(a);
        return;
    }
    for(int j =i; j<arr.size();j++){
        a.push_back(arr[j]);
        swap(arr[i], arr[j]);
        p(arr, a, ans, i+1);
        swap(arr[i],arr[j]);
        a.pop_back();
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> a;
        vector<vector<int>> ans;
        p(nums, a, ans, 0);
        return ans;
    }
};