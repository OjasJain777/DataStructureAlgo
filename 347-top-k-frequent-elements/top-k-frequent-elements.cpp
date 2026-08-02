class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;
        for(int x: nums){
            m[x]++;
            pq.push({m[x], x});
        }
        unordered_set<int> s;
        vector<int> ans;
        int l = 0;
        while(l<k){
            auto y= pq.top();
            pq.pop();
            if(s.count(y.second)==1){
                continue;
            }
            ans.push_back(y.second);
            l++;
            s.insert(y.second);
        }
        return ans;
    }
};