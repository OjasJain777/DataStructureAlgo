#include <numeric>

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int ma = INT_MIN;
        vector<int> p;

        for (int i = 0; i < nums.size(); i++) {
            ma = max(ma, nums[i]);
            p.push_back(gcd(ma, nums[i]));
        }

        sort(p.begin(), p.end());

        int i = 0;
        int j = p.size() - 1;
        long long ans = 0;

        while (i < j) {
            ans += gcd(p[i], p[j]);
            i++;
            j--;
        }

        return ans;
    }
};