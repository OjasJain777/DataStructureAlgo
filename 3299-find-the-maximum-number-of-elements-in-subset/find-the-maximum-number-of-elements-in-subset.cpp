class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> m;
        for (int x : nums) {
            m[x]++;
        }
        int ans;
        if (m[1] % 2 == 0) {
            ans = m[1] - 1;
        } else {
            ans = m[1];
        }
        long long a;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                continue;
            }
            a = nums[i];
            int c = 0;
            while (a <= 1000000000LL && m[a] >= 2) {
                c++;
                a *= a;
            }

            if (a <= 1000000000LL && m[a] == 1)
                c = c * 2 + 1;
            else
                c = c * 2 - 1;
            ans = max(ans, c);
        }
        return ans;
    }
};