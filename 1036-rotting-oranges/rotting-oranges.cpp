void d(vector<vector<int>> &grid, queue<pair<int,int>> &q1,vector<vector<bool>> &v, int &t){
    queue<pair<int, int>> q;
    if(q1.size()==0){
        return;
    }
    while(q1.size()>0){
        auto h = q1.front();
        q1.pop();
        int r = h.first;
        int c = h.second;
        if(r+1<grid.size() && grid[r+1][c] == 1 && v[r+1][c]==0){
            grid[r+1][c]=2;
            q.push({r+1, c});
            v[r+1][c]=1;
        }
        if(r-1>=0 && grid[r-1][c] == 1&& v[r-1][c] == 0){
            grid[r-1][c]=2;
            q.push({r-1,c});
            v[r-1][c]=1;
        }
        if(c+1 <grid[0].size() && grid[r][c+1]==1 && v[r][c+1]==0){
            grid[r][c+1]=2;
            q.push({r, c+1});
            v[r][c+1] = 1;
        }
        if(c-1>=0 && grid[r][c-1] == 1 && v[r][c-1]==0){
            grid[r][c-1] = 2;
            q.push({r, c-1});
            v[r][c-1]=1;
        }
    }
    if(q.size()==0){
        return;
    }
    t++;
    d(grid, q, v , t);
}
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q1;
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size(), 0));
        int t =0;
        for(int i =0; i<grid.size();i++){
            for(int j =0; j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q1.push({i,j});
                }
            }
        }
        d(grid, q1, v, t);
        for(int i =0; i<grid.size();i++){
            for(int j =0; j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return t;
    }
};