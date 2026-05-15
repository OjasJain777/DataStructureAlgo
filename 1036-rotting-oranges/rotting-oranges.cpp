class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int t =-1;
        int s = 0;
        queue<pair<int,int>> q;
        for(int i =0; i<grid.size();i++){
            for(int j =0; j<grid[0].size();j++){
                if(grid[i][j]==1){
                    s++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(s==0){
            return 0;
        }
        while(q.size()!=0){
            t++;
            int n = q.size();
            for(int k =0; k<n;k++){
                auto y = q.front();
                q.pop();
                int r = y.first;
                int c = y.second;
                if(r+1<grid.size() && grid[r+1][c]==1){
                    grid[r+1][c]=2;
                    q.push({r+1,c});
                    s--;
                }
                if(r-1>=0 && grid[r-1][c]==1){
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                    s--;
                }
                if(c+1< grid[0].size() && grid[r][c+1] ==1){
                    grid[r][c+1]= 2;
                    q.push({r,c+1});
                    s--;
                }
                if(c-1>=0 && grid[r][c-1]==1){
                    grid[r][c-1]=2;
                    q.push({r, c-1});
                    s--;
                }
            }
        }
        if(s>0){
            return -1;
        }
        return t;
    }
};