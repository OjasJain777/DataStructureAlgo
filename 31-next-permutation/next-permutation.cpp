class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        int k = -1;
        while (i >= 1) {
            if (nums[i] > nums[i - 1]) {
                k = i - 1;
                break;
            }
            i--;
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            int m = k + 1;
            for (int j = k + 2; j < nums.size(); j++) {
                if (nums[j] - nums[k] > 0 &&
                    nums[j] - nums[k] <= nums[m] - nums[k]) {
                    m = j;
                }
            }
            int b = nums[k];
            nums[k] = nums[m];
            nums[m] = b;
            reverse(nums.begin() + k+1, nums.end());
        }
    }
};