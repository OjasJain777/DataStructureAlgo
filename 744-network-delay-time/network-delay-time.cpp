class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Fast I/O trick jo Leetcode par runtime aadha kar deti hai
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // 3D vector ki jagah pair use kiya, memory allocation fast ho gayi
        vector<vector<pair<int, int>>> adj(n + 1);
        for(const auto& y: times){ // '&' use kiya taaki copy na ho, direct reference mile
            adj[y[0]].push_back({y[1], y[2]});
        }

        vector<int> ans(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        ans[0] = 0; // Tera mast jugaad wala fix
        ans[k] = 0;
        q.push({0, k});
        
        while(!q.empty()){
            auto [d, c] = q.top();
            q.pop();
            
            if(d > ans[c]) continue;
            
            // '&' use kiya taaki loop ke andar har bar pair copy na ho
            for(const auto& z: adj[c]){
                int neighbor = z.first;
                int weight = z.second;
                
                if(ans[neighbor] > d + weight){
                    ans[neighbor] = d + weight;
                    q.push({ans[neighbor], neighbor});
                }
            }
        }
        
        int a = -1;
        for(int j = 0; j < ans.size(); j++){
            if(j == k) continue;
            if(ans[j] == INT_MAX) return -1;
            a = max(a, ans[j]);
        }
        return a;
    }
};