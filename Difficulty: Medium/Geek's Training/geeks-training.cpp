class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> dp = mat[n - 1];

        for (int i = n - 2; i >= 0; i--) {

            int mx1 = INT_MIN, mx2 = INT_MIN;
            int idx1 = -1;

            for (int j = 0; j < m; j++) {
                if (dp[j] > mx1) {
                    mx2 = mx1;
                    mx1 = dp[j];
                    idx1 = j;
                } else if (dp[j] > mx2) {
                    mx2 = dp[j];
                }
            }

            vector<int> ndp(m);

            for (int j = 0; j < m; j++) {
                int best = (j == idx1 ? mx2 : mx1);
                ndp[j] = mat[i][j] + best;
            }

            dp = move(ndp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};