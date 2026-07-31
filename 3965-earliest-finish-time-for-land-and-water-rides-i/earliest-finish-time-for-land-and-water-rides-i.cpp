class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld,
                           vector<int>& ws, vector<int>& wd) {

        int minLandEnd = INT_MAX;
        int minWaterEnd = INT_MAX;

        for(int i = 0; i < ls.size(); i++)
            minLandEnd = min(minLandEnd, ls[i] + ld[i]);

        for(int i = 0; i < ws.size(); i++)
            minWaterEnd = min(minWaterEnd, ws[i] + wd[i]);

        int ans = INT_MAX;

        // Land -> Water
        for(int i = 0; i < ws.size(); i++)
            ans = min(ans, max(minLandEnd, ws[i]) + wd[i]);

        // Water -> Land
        for(int i = 0; i < ls.size(); i++)
            ans = min(ans, max(minWaterEnd, ls[i]) + ld[i]);

        return ans;
    }
};