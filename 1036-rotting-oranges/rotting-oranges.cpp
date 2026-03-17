class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q1;
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size(), 0));
        int t = 0;

        // 1. Initial scan: Find all rotten oranges
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q1.push({i, j});
                    v[i][j] = 1;
                }
            }
        }

        // 2. BFS with the 'n' snapshot trick
        while(q1.size() > 0){
            int n = q1.size(); // Current minute ke oranges ka snapshot
            bool addedNew = false; // Check if we rot any new oranges this minute

            for(int i = 0; i < n; i++){
                auto h = q1.front();
                q1.pop();
                int r = h.first;
                int c = h.second;

                // Down
                if(r+1 < grid.size() && grid[r+1][c] == 1 && v[r+1][c] == 0){
                    grid[r+1][c] = 2;
                    v[r+1][c] = 1;
                    q1.push({r+1, c});
                    addedNew = true;
                }
                // Up
                if(r-1 >= 0 && grid[r-1][c] == 1 && v[r-1][c] == 0){
                    grid[r-1][c] = 2;
                    v[r-1][c] = 1;
                    q1.push({r-1, c});
                    addedNew = true;
                }
                // Right
                if(c+1 < grid[0].size() && grid[r][c+1] == 1 && v[r][c+1] == 0){
                    grid[r][c+1] = 2;
                    v[r][c+1] = 1;
                    q1.push({r, c+1});
                    addedNew = true;
                }
                // Left
                if(c-1 >= 0 && grid[r][c-1] == 1 && v[r][c-1] == 0){
                    grid[r][c-1] = 2;
                    v[r][c-1] = 1;
                    q1.push({r, c-1});
                    addedNew = true;
                }
            }
            
            if(addedNew) t++; // Only increment time if new oranges were rotted
        }

        // 3. Final Check: Any fresh oranges left?
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return t;
    }
};