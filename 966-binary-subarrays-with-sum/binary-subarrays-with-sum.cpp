class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        vector<int> ones;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1)
                ones.push_back(i);
        }

        if(goal == 0) {
            long long ans = 0;
            long long cnt = 0;

            for(int x : nums) {
                if(x == 0) cnt++;
                else {
                    ans += cnt * (cnt + 1) / 2;
                    cnt = 0;
                }
            }

            ans += cnt * (cnt + 1) / 2;
            return ans;
        }

        if(ones.size() < goal)
            return 0;

        long long ans = 0;

        for(int i = 0; i + goal - 1 < ones.size(); i++) {

            int j = i + goal - 1;

            int leftZeros =
                (i == 0)
                ? ones[i]
                : ones[i] - ones[i - 1] - 1;

            int rightZeros =
                (j == ones.size() - 1)
                ? nums.size() - 1 - ones[j]
                : ones[j + 1] - ones[j] - 1;

            ans += 1LL * (leftZeros + 1) * (rightZeros + 1);
        }

        return ans;
    }
};