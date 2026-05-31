class Solution {
  public:
    int largest(vector<int> &arr) {
        int ans =INT_MIN;
        for(int x: arr){
            ans = max(x, ans);
        }
        return ans;
    }
};
