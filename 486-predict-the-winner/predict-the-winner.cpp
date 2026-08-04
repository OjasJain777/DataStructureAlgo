class Solution {
public:
    int f(int l, int r, bool p, vector<int>& nums,
          vector<vector<vector<int>>> &dp) {

        if (l > r) return 0;

        if (dp[l][r][p] != -1)
            return dp[l][r][p];

        if (p) {
            return dp[l][r][p] = max(
                nums[l] + f(l + 1, r, 0, nums, dp),
                nums[r] + f(l, r - 1, 0, nums, dp)
            );
        }

        return dp[l][r][p] = min(
            f(l + 1, r, 1, nums, dp),
            f(l, r - 1, 1, nums, dp)
        );
    }

    bool predictTheWinner(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;

        int n = nums.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, -1))
        );

        int p1 = f(0, n - 1, 1, nums, dp);

        return p1 >= total - p1;
    }
};