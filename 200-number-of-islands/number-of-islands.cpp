class Solution {
public:
    void bfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        
        q.push({r, c});
        grid[r][c] = '0'; // Mark as visited immediately

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [currI, currJ] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = currI + dx[k];
                int nj = currJ + dy[k];

                // Check boundaries and if it's land
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                    grid[ni][nj] = '0'; // Sink the land so we don't visit it again
                    q.push({ni, nj});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int t = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    t++;
                    bfs(grid, i, j);
                }
            }
        }
        return t;
    }
};