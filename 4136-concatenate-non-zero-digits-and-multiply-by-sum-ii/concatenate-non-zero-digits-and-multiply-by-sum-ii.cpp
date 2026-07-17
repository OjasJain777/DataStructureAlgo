class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;

        vector<long long> n(s.size(), 0);
        vector<int> l(s.size(), 0);
        vector<int> d(s.size(), 0);

        vector<long long> pow10(s.size() + 1);
        pow10[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            pow10[i] = (pow10[i - 1] * 10) % mod;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] > '0' && s[i] <= '9') {
                if (i == 0) {
                    d[i] = s[i] - '0';
                    l[i] = 1;
                    n[i] = s[i] - '0';
                } else {
                    d[i] = d[i - 1] + (s[i] - '0');
                    l[i] = l[i - 1] + 1;
                    n[i] = (1LL * n[i - 1] * 10 + (s[i] - '0')) % mod;
                }
            } else if (i != 0) {
                d[i] = d[i - 1];
                n[i] = n[i - 1];
                l[i] = l[i - 1];
            }
        }

        vector<int> ans;

        for (auto &y : queries) {
            int L = y[0], R = y[1];

            long long b = n[R];
            long long sum = d[R];

            if (L) {
                sum = d[R] - d[L - 1];

                int cnt = l[R] - l[L - 1];

                b = (n[R] - (1LL * n[L - 1] * pow10[cnt]) % mod + mod)%mod;
            }

            sum %= mod;

            ans.push_back((1LL * b * sum) % mod);
        }

        return ans;
    }
};