void p(vector<int> &arr, vector<int> &a, vector<vector<int>> &ans, unordered_map<int,int> &b, int i){
    if(i == arr.size()){
        ans.push_back(a);
        return;
    }
    for(int j =0; j<arr.size();j++){
        if(b[j]==0){
            a.push_back(arr[j]);
            b[j]++;
            p(arr, a, ans, b, i+1);
            b[j]--;
            a.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> a;
        vector<vector<int>> ans;
        unordered_map<int,int> b;
        p(nums, a, ans,b, 0);
        return ans;
    }
};