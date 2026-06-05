class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<bool> s(sum+1, 0);
        s[0] = 1;
        for(int i =0;i<arr.size();i++){
            for(int j = sum; j>=0;j--){
                if(s[j] && j + arr[i] <= sum){
                    s[j + arr[i]] = 1;
                }
                if(s[s.size()-1]==1){
                    return 1;
                }
            }
        }
        return 0;
    }
};