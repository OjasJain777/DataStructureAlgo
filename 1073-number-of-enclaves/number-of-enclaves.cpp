class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int k =0;k<grid.size();k++){
            if(grid[k][0]==1){
                q.push({k,0});
                grid[k][0]=0;
            }
            if(grid[k][grid[0].size()-1]==1){
                q.push({k, grid[0].size()-1});
                grid[k][grid[0].size()-1]=0;
            }
        }
        for(int k =0; k<grid[0].size();k++){
            if(grid[0][k] == 1){
                q.push({0, k});
                grid[0][k]=0;
            }
            if(grid[grid.size()-1][k]==1){
                q.push({grid.size()-1, k});
                grid[grid.size()-1][k] = 0;
            }
        }
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0,0, 1,-1};
        while(q.size()>0){
            auto y = q.front();
            int i = y.first;
            int j = y.second;
            q.pop();
            for(int k =0; k<dx.size();k++){
                if(i+dx[k]>=0 && i+dx[k]< grid.size() && j+dy[k] >=0 && j+dy[k] < grid[0].size() && grid[i+dx[k]][j+dy[k]] == 1){
                    q.push({i+dx[k], j+dy[k]});
                    grid[i+dx[k]][j+dy[k]] = 0;
                }
            }
        }
        int t =0;
        for(int r =0; r<grid.size();r++){
            for(int c = 0; c< grid[0].size(); c++){
                if(grid[r][c]==1){
                    t++;
                }
            }
        }
        return t;
    }
};