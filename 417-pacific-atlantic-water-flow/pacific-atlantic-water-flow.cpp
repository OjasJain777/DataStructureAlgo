class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> v(heights.size(), vector<bool>(heights[0].size(),0));
        queue<pair<int,int>> q;
        vector<vector<int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0; i<heights[0].size();i++){
            q.push({0, i});
            v[0][i]=1;
        }
        for(int i =1 ; i<heights.size();i++){
            q.push({i, 0});
            v[i][0] =1;
        }
        while(!q.empty()){
            auto [r,c]= q.front();
            q.pop();
            for(auto &x : d){
                if(r+x[0] >=0 && r+x[0] < heights.size() && c+x[1] >=0 && c+x[1]<heights[0].size() && v[r+x[0]][c+x[1]] == 0 && heights[r][c] <= heights[r+x[0]][c+x[1]]){
                    q.push({r+x[0], c+x[1]});
                    v[r+x[0]][c+x[1]] = 1;
                }
            }
        }
        vector<vector<bool>> v2(heights.size(), vector<bool>(heights[0].size(),0));
        vector<vector<int>> ans;
        for(int i = 0; i<heights.size()-1;i++){
            q.push({i, heights[0].size()-1});
            v2[i][ heights[0].size()-1] = 1;
        }
        for(int i = 0; i<heights[0].size();i++){
            q.push({heights.size()-1, i});
            v2[heights.size()-1][i] = 1;
        }
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            if(v[r][c] == 1){
                ans.push_back({r,c});
            }
            for(auto &x : d){
                if(r+x[0] >=0 && c+x[1] >=0 && r+x[0] < heights.size() && c + x[1] < heights[0].size() && v2[r+x[0]][c+x[1]] == 0 && heights[r][c] <= heights[r+x[0]][c+x[1]]){
                    q.push({r+x[0],c+x[1]});
                    v2[r+x[0]][c+x[1]] = 1;
                }
            }
        }
        return ans;
    }
};