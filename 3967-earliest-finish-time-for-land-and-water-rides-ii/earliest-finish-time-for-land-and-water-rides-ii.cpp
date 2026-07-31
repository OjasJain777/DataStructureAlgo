class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int mi = INT_MAX;
        for(int i= 0; i<ls.size();i++){
            mi = min(mi,ls[i]+ld[i]);
        }
        int ans = INT_MAX;
        for(int j = 0 ; j<ws.size();j++){
            ans = min(ans,max(ws[j], mi) + wd[j]);
        }
        mi = INT_MAX;
        for(int i = 0; i<ws.size();i++){
            mi = min(ws[i]+wd[i], mi);
        }
        for(int j = 0; j<ls.size();j++){
            ans = min(ans, max(ls[j], mi) + ld[j]);
        }
        return ans;
    }
};