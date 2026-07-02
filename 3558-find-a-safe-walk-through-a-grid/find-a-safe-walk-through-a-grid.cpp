class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size(),0));
        q.push({grid[0][0],0,0});
        while(q.size()!=0){
            auto y = q.top();
            q.pop();
            if(v[y[1]][y[2]]){
                continue;
            }
            v[y[1]][y[2]] =1;
            if(y[1] == grid.size()-1 && y[2] == grid[0].size()-1){
                if(y[0] < health){
                    return 1;
                }
                return 0;
            }
            for(auto x: d){
                if(y[1] + x[0] < grid.size() && y[1] + x[0] >=0 && y[2]+x[1] >=0 && y[2] + x[1] < grid[0].size() && v[y[1] + x[0]][y[2] + x[1]]==0){
                    q.push({y[0] + grid[y[1] + x[0]][y[2]+x[1]], y[1]+x[0], y[2] + x[1]});
                }
            }
        }
        return 0;
    }
};