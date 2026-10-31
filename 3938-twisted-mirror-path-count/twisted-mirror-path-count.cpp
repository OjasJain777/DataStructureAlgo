class Solution {
public:
    int mod = 1e9 + 7;

    int t(int i, int j, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp, int d) {

        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n)
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(dp[i][j][d] != -1)
            return dp[i][j][d];

        long long ans = 0;

        if(grid[i][j] == 0) {

            // Empty cell: choose either direction
            ans = (t(i+1, j, grid, dp, 0) +
                   t(i, j+1, grid, dp, 1)) % mod;

        }
        else {

            // Mirror: automatically change direction
            if(d == 0) {
                // Entered while moving DOWN -> redirect RIGHT
                ans = t(i, j+1, grid, dp, 1);
            }
            else {
                // Entered while moving RIGHT -> redirect DOWN
                ans = t(i+1, j, grid, dp, 0);
            }
        }

        return dp[i][j][d] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if(m == 1 && n == 1)
            return 1;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, -1))
        );

        // First move DOWN or RIGHT
        return (t(1, 0, grid, dp, 0) +
                t(0, 1, grid, dp, 1)) % mod;
    }
};