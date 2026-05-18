class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> ans(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<vector<vector<int>>> adj(n+1);
        for(auto y: times){
            adj[y[0]].push_back({y[1],y[2]});
        }
        ans[0]=0;
        ans[k]=0;
        q.push({0,k});
        while(q.size()!=0){
            auto [d,c] = q.top();
            q.pop();
            if(d>ans[c]){
                continue;
            }
            for(auto z: adj[c]){
                if(ans[z[0]] > ans[c] + z[1]){
                    ans[z[0]] = ans[c] + z[1];
                    q.push({ans[z[0]], z[0]});
                }
            }
        }
        int a = -1;
        for(int j =0; j<ans.size();j++){
            if(j==k){
                continue;
            }
            if(ans[j]==INT_MAX){
                return -1;
            }
            a = max(a, ans[j]);
        }
        return a;
    }
};