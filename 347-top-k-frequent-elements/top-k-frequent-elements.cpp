class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<unordered_set<int>> v(nums.size()+1);
        unordered_map<int,int> m;
        for(int x: nums){
            if(m[x]!=0){
                v[m[x]].erase(x);
            }
            m[x]++;
            v[m[x]].insert(x);
        }
        int j = v.size()-1;
        vector<int> ans;
        while(k>0){
            if(v[j].size()==0){
                j--;
                continue;
            }
            for(int x: v[j]){
                if(k==0){
                    return ans;
                }
                ans.push_back(x);
                k--;
            }
            j--;
        }
        return ans;
    }
};