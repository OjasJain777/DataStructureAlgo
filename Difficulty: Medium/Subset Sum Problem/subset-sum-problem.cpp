class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        unordered_set<int> s;
        s.insert(0);
        for(int i =0; i<arr.size();i++){
            unordered_set<int> p=s;
            for(auto y: p){
                s.insert(y+arr[i]);
            }
            if(s.count(sum)==1){
                return 1;
            }
        }
        return 0;
    }
};