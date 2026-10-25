class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 || vis[i][j]) {
                    continue;
                }

                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;

                bool boundary = false;

                while (!q.empty()) {
                    auto [r, col] = q.front();
                    q.pop();

                    if (r == 0 || r == m - 1 ||
                        col == 0 || col == n - 1) {
                        boundary = true;
                    }

                    for (int k = 0; k < 4; k++) {
                        int nr = r + dr[k];
                        int nc = col + dc[k];

                        if (nr >= 0 && nr < m &&
                            nc >= 0 && nc < n &&
                            grid[nr][nc] == 0 &&
                            !vis[nr][nc]) {
                            vis[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }

                if (!boundary) {
                    ans++;
                }
            }
        }

        return ans;
    }
};