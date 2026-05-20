class Solution {
public:

    int findTheCity(int n,
                    vector<vector<int>>& edges,
                    int distanceThreshold) {

        const int INF = 1e9;

        vector<vector<int>> dist(
            n, vector<int>(n, INF)
        );

        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall
        for(int k = 0; k < n; k++) {

            for(int i = 0; i < n; i++) {

                // tiny cache optimization
                int dik = dist[i][k];

                for(int j = 0; j < n; j++) {

                    if(dik + dist[k][j] < dist[i][j]) {

                        dist[i][j] =
                            dik + dist[k][j];
                    }
                }
            }
        }

        int bestCity = -1;
        int minCnt = INT_MAX;

        for(int i = 0; i < n; i++) {

            int cnt = 0;

            for(int j = 0; j < n; j++) {

                if(dist[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }

            if(cnt <= minCnt) {

                minCnt = cnt;
                bestCity = i;
            }
        }

        return bestCity;
    }
};