class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& c) {
        int ans =0;
        sort(c.begin(), c.end(), [](vector<int> a, vector<int> b){
            return a[0]-a[1] > b[0]-b[1];
        });
        for(int i =0; i<c.size();i++){
            if(i<c.size()/2){
                ans += c[i][1];
            }
            else{
                ans += c[i][0];
            }
        }
        return ans;
    }
};