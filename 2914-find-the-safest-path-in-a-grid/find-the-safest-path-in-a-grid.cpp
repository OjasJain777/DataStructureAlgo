class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1) return 0;

        queue<pair<int,int>> q;
        vector<pair<int,int>> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // Multi-source BFS
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    grid[i][j] = 0;
                }
                else{
                    grid[i][j] = -1;
                }
            }
        }

        int dist = 0;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto [r,c] = q.front();
                q.pop();

                grid[r][c] = dist;

                for(auto [dr,dc] : d){
                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==-1){
                        grid[nr][nc] = -2;
                        q.push({nr,nc});
                    }
                }
            }
            dist++;
        }

        // Modified Dijkstra
        priority_queue<vector<int>> pq;
        vector<vector<int>> vis(n, vector<int>(n,0));

        pq.push({grid[0][0],0,0});

        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int val = cur[0];
            int r = cur[1];
            int c = cur[2];

            if(vis[r][c]) continue;
            vis[r][c]=1;
            if(r == n-1 && c == n-1)
                return val;
            for(auto [dr,dc] : d){

                int nr = r + dr;
                int nc = c + dc;

                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){

                    pq.push({min(val, grid[nr][nc]), nr, nc});
                }
            }
        }

        return 0;
    }
};