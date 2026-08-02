class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &[num, f] : freq)
            bucket[f].push_back(num);

        vector<int> ans;

        for (int f = nums.size(); f >= 1 && ans.size() < k; f--) {
            for (int num : bucket[f]) {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};