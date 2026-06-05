bool t(int k, int &sum, int s, int r ,vector<int> &arr){
    if(s > sum){
        return 0;
    }
    if(r+s<sum){
        return 0;
    }
    if(s==sum){
        return 1;
    }
    if(k>=arr.size()){
        return 0;
    }
    return t(k+1, sum, s+arr[k], r-arr[k], arr) || t(k+1, sum, s, r-arr[k],arr);
}
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int c =0;
        for(auto x: arr){
            c+=x;
        }
        return t(0, sum, 0, c, arr);
    }
};