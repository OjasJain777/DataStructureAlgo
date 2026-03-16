class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int n = (image.size())*(image[0].size());
        vector<vector<bool>> v(image.size(), vector<bool>(image[0].size(), 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        v[sr][sc]=1;
        int o = image[sr][sc];
        while(q.size()>0){
            auto c = q.front();
            image[c.first][c.second] = newColor;
            q.pop();
            sr = c.first;
            sc = c.second;
            if(sr+1 < image.size() && image[sr+1][sc]==o && v[sr+1][sc]==0){
                q.push({sr+1, sc});
                v[sr+1][sc]=1;
            }
            if(sr-1>=0 && image[sr-1][sc]==o && v[sr-1][sc]==0){
                q.push({sr-1, sc});
                v[sr-1][sc]=1;
            }
            if(sc+1<image[0].size() && image[sr][sc+1] == o && v[sr][sc+1]==0){
                q.push({sr, sc+1});
                v[sr][sc+1]=1;
            }
            if(sc-1>=0 && image[sr][sc-1]==o && v[sr][sc-1]==0){
                q.push({sr, sc-1});
                v[sr][sc-1] = 1;
            }
        }
        return image;
    }
};