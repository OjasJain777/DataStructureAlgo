class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int R = mat.size(), C = mat[0].size();
        queue<pair<int, int>> q;
        
        // Using mat itself to track visited: 0 stays 0, 1 becomes -1 (unvisited)
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (mat[r][c] == 0) {
                    q.push({r, c});
                } else {
                    mat[r][c] = -1; // Mark as unvisited
                }
            }
        }

        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); 
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];

                // If within bounds AND unvisited (-1)
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && mat[nr][nc] == -1) {
                    mat[nr][nc] = mat[r][c] + 1; // Distance = Parent distance + 1
                    q.push({nr, nc});
                }
            }
        }
        return mat;
    }
};