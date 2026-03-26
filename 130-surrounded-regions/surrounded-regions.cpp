class Solution {
public:
    void bfs(int startI, int startJ, vector<vector<char>>& board, vector<vector<bool>>& v) {
        int m = board.size();
        int n = board[0].size();
        
        queue<pair<int, int>> q;
        vector<pair<int, int>> currentIsland; // To store all 'O's in the current group
        bool touchesBorder = false;

        q.push({startI, startJ});
        v[startI][startJ] = true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            currentIsland.push_back(curr);

            int i = curr.first;
            int j = curr.second;

            // If ANY cell in this island is on the edge, the whole island is safe
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                touchesBorder = true;
            }

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O' && !v[ni][nj]) {
                    v[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }

        // Decision phase: Only flip if the island was completely surrounded (didn't touch border)
        if (!touchesBorder) {
            for (auto& cell : currentIsland) {
                board[cell.first][cell.second] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> v(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we find an 'O' we haven't processed yet, start a BFS
                if (board[i][j] == 'O' && !v[i][j]) {
                    bfs(i, j, board, v);
                }
            }
        }
    }
};