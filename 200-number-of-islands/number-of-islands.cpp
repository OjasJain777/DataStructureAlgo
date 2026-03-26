void bfs(vector<vector<char>> &grid, vector<vector<bool>> &v, queue<pair<int,int>> &q){
    while(q.size()>0){
        auto y = q.front();
        q.pop();
        int i = y.first;
        int j = y.second;        
        vector<int> dx = {1 ,-1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        for(int k =0; k<dx.size(); k++){
            if( i+ dx[k] < grid.size() && i+dx[k]>=0 && j + dy[k] < grid[0].size() && j+dy[k] >=0 && grid[i+dx[k]][j+dy[k]]=='1' && v[i+dx[k]][j+dy[k]]==0){
                q.push({i+dx[k], j+dy[k]});
                v[i+dx[k]][j+dy[k]] = 1;
            }
        }
    }
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size()));
        int t =0;
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                if(grid[i][j]=='1' && v[i][j]==0){
                    t++;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    v[i][j]=1;
                    bfs(grid, v, q);
                }
            }
        }
        return t;
    }
};