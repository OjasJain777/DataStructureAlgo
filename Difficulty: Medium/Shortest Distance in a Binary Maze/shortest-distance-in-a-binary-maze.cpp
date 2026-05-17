// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(),-1));
        ans[source.first][source.second] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, source.first, source.second});
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        while(q.size()!=0){
            auto z = q.top();
            q.pop();
            int d = z[0];
            int r = z[1];
            int c = z[2];
            if(d > ans[r][c]){
                continue;
            }
            if(r == destination.first && c == destination.second){
                return d;
            }
            for(int i =0; i<dx.size();i++){
                if(r+dx[i]>=0 && r+dx[i]<grid.size() && c+dy[i] >=0 && c + dy[i] < grid[0].size() && grid[r+dx[i]][c+dy[i]] == 1){
                    if(ans[r+dx[i]][c+dy[i]] == -1 || ans[r+dx[i]][c+dy[i]] > d + 1){
                        ans[r+dx[i]][c+dy[i]]= d+1;
                        q.push({d+1, r+dx[i], c+dy[i]});
                    }
                }
            }
        }
        return -1;
    }
};
