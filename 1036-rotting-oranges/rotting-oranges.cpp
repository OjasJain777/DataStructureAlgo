class Solution {
public:
    void d(vector<vector<int>> &grid, queue<pair<int,int>> q1, vector<vector<bool>> &v, int &t){
        queue<pair<int, int>> q; // Ye agli minute ke oranges ke liye hai
        
        if(q1.size() == 0) return; // Base case: Jab koi orange sadata nahi bacha

        while(q1.size() > 0){
            auto h = q1.front();
            q1.pop();
            int r = h.first;
            int c = h.second;

            // Down: v[r+1] check hoga, typo mat karna
            if(r+1 < grid.size() && grid[r+1][c] == 1 && v[r+1][c] == 0){
                grid[r+1][c] = 2;
                q.push({r+1, c});
                v[r+1][c] = 1;
            }
            // Up
            if(r-1 >= 0 && grid[r-1][c] == 1 && v[r-1][c] == 0){
                grid[r-1][c] = 2;
                q.push({r-1, c});
                v[r-1][c] = 1;
            }
            // Right: boundary check < grid[0].size()
            if(c+1 < grid[0].size() && grid[r][c+1] == 1 && v[r][c+1] == 0){
                grid[r][c+1] = 2;
                q.push({r, c+1});
                v[r][c+1] = 1;
            }
            // Left
            if(c-1 >= 0 && grid[r][c-1] == 1 && v[r][c-1] == 0){
                grid[r][c-1] = 2;
                q.push({r, c-1});
                v[r][c-1] = 1;
            }
        }

        // Agar agli minute ke liye koi orange sada hai (q khali nahi hai)
        if(q.size() > 0){
            t++;
            d(grid, q, v, t); // Agle minute ke liye recursion call
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q1;
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size(), 0));
        int t = 0;

        // 1. Pehle saare rotten oranges dhoond ke q1 mein bharo
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q1.push({i, j});
                    v[i][j] = 1;
                }
            }
        }

        // 2. Ab function call karo taaki infection faile
        d(grid, q1, v, t);

        // 3. Last mein check karo koi orange fresh reh toh nahi gaya
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return t;
    }
};