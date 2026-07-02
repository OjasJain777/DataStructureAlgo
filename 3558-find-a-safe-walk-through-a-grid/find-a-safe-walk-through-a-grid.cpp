vector<vector<int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<vector<int>> q;
        q.push({health, 0,0});
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size(),0));
        while(q.size()!=0){
            auto y = q.top();
            int h = y[0];
            q.pop();
            int r= y[1];
            int c = y[2];
            if(v[r][c]==1){
                continue;
            }
            v[r][c]=1;
            if(grid[r][c]==1){
                if(h==1){
                    continue;
                }
                h--;
            }
            if(r==grid.size()-1 && c==grid[0].size()-1){
                return 1;
            }
            for(auto x : d){
                if(r+x[0] >=0 && r+x[0] < grid.size() && c+x[1] >=0 && c + x[1] < grid[0].size() && v[r+x[0]][c+x[1]]==0){
                    q.push({h, r+x[0], c+x[1]});
                }
            }
        }
        return 0;
    }
};