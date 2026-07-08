class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> v(N, vector<bool>(M, false));
        vector<vector<int>> d = {{1,0},{-1,0},{0,-1},{0,1}};

        // First and Last Row
        for(int j = 0; j < M; j++){
            if(grid[0][j] == 1){
                q.push({0, j});
                v[0][j] = true;
            }

            if(grid[N-1][j] == 1 && !v[N-1][j]){
                q.push({N-1, j});
                v[N-1][j] = true;
            }
        }

        // First and Last Column
        for(int i = 0; i < N; i++){
            if(grid[i][0] == 1 && !v[i][0]){
                q.push({i, 0});
                v[i][0] = true;
            }

            if(grid[i][M-1] == 1 && !v[i][M-1]){
                q.push({i, M-1});
                v[i][M-1] = true;
            }
        }

        while(!q.empty()){
            auto y = q.front();
            q.pop();

            int r = y.first;
            int c = y.second;

            for(auto &x : d){
                if(r + x[0] >= 0 && r + x[0] < N &&
                   c + x[1] >= 0 && c + x[1] < M &&
                   !v[r + x[0]][c + x[1]] &&
                   grid[r + x[0]][c + x[1]] == 1){

                    q.push({r + x[0], c + x[1]});
                    v[r + x[0]][c + x[1]] = true;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 1 && !v[i][j]){
                    ans++;
                }
            }
        }

        return ans;
    }
};