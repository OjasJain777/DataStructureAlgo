class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> ans(heights.size(), vector<int>(heights[0].size(),INT_MAX));
        ans[0][0]=0;
        q.push({0, {0, 0}});
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        while(q.size()!=0){
            auto z = q.top();
            int d = z.first;
            int r = z.second.first;
            int c = z.second.second;
            q.pop();
            if(r== heights.size()-1 && c == heights[0].size()-1){
                return d;
            }
            for(int k = 0; k<dx.size();k++){
                if(r+dx[k]>=0 && c+dy[k]>=0 && r+dx[k]<heights.size() && c+dy[k]<heights[0].size()){
                    int x = max(ans[r][c], abs(heights[r][c] - heights[r+dx[k]][c+dy[k]]));
                    if(ans[r+dx[k]][c+dy[k]] > x){
                        ans[r+dx[k]][c+dy[k]] = x;
                        q.push({x, {r+dx[k], c+dy[k]}});
                    }
                }
            }
        }
        return ans[heights.size()-1][heights[0].size()-1];
    }
};