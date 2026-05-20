class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        const long long INF = 1e18;

        vector<vector<long long>> adj(
            n, vector<long long>(n, INF)
        );

        for(auto &y : edges){
            adj[y[0]][y[1]] = y[2];
            adj[y[1]][y[0]] = y[2];
        }

        for(int i = 0; i < n; i++){
            adj[i][i] = 0;
        }

        // Floyd-Warshall
        for(int k = 0; k < n; k++){

            for(int i = 0; i < n; i++){

                for(int j = 0; j < n; j++){

                    if(adj[i][k] == INF ||
                       adj[k][j] == INF)
                        continue;

                    adj[i][j] = min(
                        adj[i][j],
                        adj[i][k] + adj[k][j]
                    );
                }
            }
        }

        int minReachable = INT_MAX;
        int city = -1;

        for(int i = 0; i < n; i++){

            int cnt = 0;

            for(int j = 0; j < n; j++){

                if(adj[i][j] <= distanceThreshold){
                    cnt++;
                }
            }

            // larger index on tie
            if(cnt <= minReachable){

                minReachable = cnt;
                city = i;
            }
        }

        return city;
    }
};