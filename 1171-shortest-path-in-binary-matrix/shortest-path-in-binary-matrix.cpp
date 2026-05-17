class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<bool>> v(grid.size(),vector<bool>(grid.size(),0));
        queue<pair<int, int>> q;
        vector<int> dx = {1, 1, -1, -1, 1,-1, 0, 0};
        vector<int> dy = {1, -1, 1, -1, 0,0, 1, -1};
        if(grid[0][0]==0){
            q.push({0,0});
            v[0][0] = 1;
        }
        int d =1;
        while(q.size()!=0){
            int n = q.size();
            for(int k =0; k<n;k++){
                auto [r,c] = q.front();
                q.pop();
                if(r==c && c == grid.size()-1){
                    return d;
                }
                for(int i =0 ; i<dx.size(); i++){
                    if(r+dx[i]>=0 && r+dx[i]<grid.size() && c+dy[i]>=0 && c+dy[i]<grid[0].size() && grid[r+dx[i]][c+dy[i]]==0 && v[r+dx[i]][c+dy[i]]==0){
                        q.push({r+dx[i], c+dy[i]});
                        v[r+dx[i]][c+dy[i]]=1;
                    }
                }
            }
            d++;
        }
        return -1;
    }
};