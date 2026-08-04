int gs(int n){
    if(n<=0){
        return 0;
    }
    int s = ((n)*(n+1))/2;
    return s;
}
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mi = INT_MAX;
        int ma = INT_MIN;
        unordered_set<int> s;
        for(int x: nums){
            mi = min(mi, x);
            ma = max(ma, x);
            s.insert(x);
        }
        vector<int> ans;
        for(int i = mi; i<=ma;i++){
            if(s.count(i)==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};