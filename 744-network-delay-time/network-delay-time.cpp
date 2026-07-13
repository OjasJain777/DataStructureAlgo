class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> d(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        vector<vector<vector<int>>> adj(n+1);
        for(auto &y: times){
            adj[y[0]].push_back({y[1],y[2]});
        }
        d[k]=0;
        while(!q.empty()){
            auto y= q.top();
            q.pop();
            int cd = y.first;
            int cn = y.second;
            if(cd > d[cn]){
                continue;
            }
            for(auto &x: adj[cn]){
                if(d[x[0]] > cd + x[1]){
                    d[x[0]] = cd + x[1];
                    q.push({d[x[0]], x[0]});
                }   
            }
        }
        int ans = -1;
        for(int i =1 ; i<n+1;i++){
            ans = max(ans, d[i]);
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};