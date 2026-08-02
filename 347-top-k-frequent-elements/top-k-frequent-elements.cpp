class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<unordered_set<int>> bucket(nums.size() + 1);

        for (int x : nums) {
            int f = freq[x];
            if (f) bucket[f].erase(x);

            freq[x]++;
            bucket[f + 1].insert(x);
        }

        vector<int> ans;

        for (int f = nums.size(); f >= 1 && k > 0; f--) {
            for (int x : bucket[f]) {
                ans.push_back(x);
                if (--k == 0) return ans;
            }
        }

        return ans;
    }
};